 #include "Fix_Cache.h"

//�����ļ��ܻ�ӭ�Ȳ�����վ���棬ln,i
 void Cache_Generator(int (& Cache_State)[MaxRelayNum][MaxFileNum])
{
    //��ʼ��	
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

//���������վ���棬ln,i
 /*void Cache_Generator(int (& Cache_State)[MaxRelayNum][MaxFileNum])
{
    //��ʼ��	
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

 //�ӱ����ļ��ж�ȡ
 void Cache_read(int (& Cache_State)[MaxRelayNum][MaxFileNum])
 {
	//��ʼ��	
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
	 file.open("F:\\cache_state_3\\SBS_caching_��0.0.txt");  //���û����йأ���50���û����˴�Ϊcache_state_1�ļ����е�SBS_cahing_50.txt���뻺��ռ��йأ���1%���˴�Ϊcache_state_2�е�SBS_caching_1.txt
	 for(i=0; i<MaxRelayNum; i++)
	 {
		 for(j=0; j<100; j++)
		 {
			 file>>Cache_State[i][j];
		 }
	 }

 }


//��ʾ����״̬
void Print_CacheState(int (& Cache_State)[MaxRelayNum][MaxFileNum])
{
	cout<<"��վ����״̬Ϊ�� "<<endl;
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

//����Ŀ�꺯����ln,i��ֵ
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
	cout<<"Ŀ�꺯���еڶ����ֵΪ��"<<result<<endl;
}