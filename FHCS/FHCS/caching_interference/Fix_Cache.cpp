 #include "Fix_Cache.h"

//按照文件受欢迎度产生基站缓存，ln,i
 void Cache_Generator(int (& Cache_State)[MaxRelayNum][MaxFileNum])
{
    //初始化	
	int i=0; 
	int j=0;
	for(i=0;i<MaxRelayNum;i++)           
	{
		for( j=0;j<MaxFileNum;j++)
		{
			Cache_State[i][j]=0;       
		}
	}	
	for(i=0; i<MaxRelayNum; ++i)
	{
	    for( j=0; j<Cache_Max; ++j)
     		Cache_State[i][j] = 1;
	}
}

//随机产生基站缓存，ln,i
 /*void Cache_Generator(int (& Cache_State)[MaxRelayNum][MaxFileNum])
{
    //初始化	
	int i=0; 
	int j=0;
	for(i=0;i<MaxRelayNum;i++)           
	{
		for( j=0;j<MaxFileNum;j++)
		{
			Cache_State[i][j]=0;       
		}
	}
	for(i=0; i<MaxRelayNum; ++i)
	{
	    int count = 0;
		while(count < Cache_Max)
		{
		    int temp = rand()%MaxFileNum;
			if(Cache_State[i][temp] == 0)
			{
			    Cache_State[i][temp] = 1;
			    ++count;
			}
		}
	}
}*/

 //从本地文件中读取
 void Cache_read(int (& Cache_State)[MaxRelayNum][MaxFileNum])
 {
	//初始化	
	int i=0; 
	int j=0;
	for(i=0;i<MaxRelayNum;i++)           
	{
		for( j=0;j<MaxFileNum;j++)
		{
			Cache_State[i][j]=0;       
		}
	}
	 ifstream file;
	 file.open("F:\\cache_state_3\\SBS_caching_γ0.0.txt");  //与用户数有关，如50个用户，此处为cache_state_1文件夹中的SBS_cahing_50.txt；与缓存空间有关，如1%，此处为cache_state_2中的SBS_caching_1.txt
	 for(i=0; i<MaxRelayNum; i++)
	 {
		 for(j=0; j<100; j++)
		 {
			 file>>Cache_State[i][j];
		 }
	 }

 }


//显示缓存状态
void Print_CacheState(int (& Cache_State)[MaxRelayNum][MaxFileNum])
{
	cout<<"基站缓存状态为： "<<endl;
	for(int i=0;i<MaxRelayNum;i++)
	{
		for(int j=0;j<MaxFileNum;j++)
		{
		    cout<<Cache_State[i][j]<<" ";
		}
		cout<<endl;		
	}
	cout<<endl;	
}

//计算目标函数中ln,i的值
void Calculate_LNI(int (& Cache_State)[MaxRelayNum][MaxFileNum], int (& NodeNeighborTable)[MaxRelayNum][MaxUserNum], int (& User_Request)[MaxUserNum][MaxFileNum] )
{
    int result = 0;
    for(int i=0;i<MaxRelayNum;i++)
    {
	    for(int j=0;j<MaxFileNum;j++)
	    {
		
		    for(int k=0;k<MaxUserNum;k++ )
		    {
			    if((Cache_State[i][j]) && (NodeNeighborTable[i][k]==1) && (User_Request[k][j]==1))
			    {
				    ++result;
			    }
		    }
	       
	    }
    }
	ofstream file;
	file.open("2.txt");
	file<<result;
	file.close();
	cout<<"目标函数中第二项的值为："<<result<<endl;
}