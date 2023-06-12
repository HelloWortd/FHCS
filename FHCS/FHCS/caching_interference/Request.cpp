#include "Request.h"
#include <math.h>
unsigned long ulrand( );
//�ļ��ܻ�ӭ��
void Pro_Generator(double *p)
{
	double deno = 0.0;   //��ĸ
	double nume = 0.0;   //����
	double temp = 0.0;
	//�����ĸ
	for(int i=1;i<=MaxFileNum;i++)
	{
		temp = double(1/pow(i,��));
		deno+=temp;
	}
	//cout<<"deno: "<<deno<<endl;
	for(int j=1;j<=MaxFileNum;j++)
	{
		//�������
		nume = double(1/pow(j,��));
		//�������
		p[j-1]=double(nume/deno);
	}
}
void Print_Pro( double *p)
{
	cout<<"�ļ��ܻ�ӭ��Ϊ��"<<endl;
	for(int i=0;i<MaxFileNum;i++)
	{
		cout<<p[i]<<" ";
	}
	cout<<endl;
}


//���ļ��ܻ�ӭ������������ĵ�
void Out_Pro(double (& Pro)[MaxFileNum])
{
	ofstream file;
	file.open("�ļ��ܻ�ӭ��-��1.5.txt");
		for(int j=0;j<MaxFileNum;j++)
		{
			file<<Pro[j]<<" ";
			file<<endl;
		}
		file<<endl;
	file.close();
}



//�û������ļ��ܻ�ӭ�Ȳ����ļ�����
void Request_Generator(int (& User_Request)[MaxUserNum][MaxFileNum], double *File_Pro)
{
  	int max = File_Pro[0]*pow(10.0, 7);
	srand((unsigned)time(0)) ;
	for(int i=0;i<MaxUserNum;i++)
    {
	    
        int rand1 = rand() %10000;
        int rand2 = rand() % 10000;
        int randV = (rand1 * 10000 + rand2) % (max + 1);//�ĳ�����   
        int x = randV;
		
		if(x <= File_Pro[MaxFileNum-1]*pow(10.0,7) )        //�жϵ�0���ļ�
		{
			User_Request[i][MaxFileNum-1]=1;
		}
		else                     //�ж�ʣ���ļ�
		{
			int j=0;
			while(j<(MaxFileNum-1))
			{
				if((x > File_Pro[j+1]*pow(10.0,7)) && (x <= File_Pro[j]*pow(10.0,7)))
				{
					User_Request[i][j]=1;
					break;
				}
				else
				{
					j++;
				}
			}
			//if(MaxFileNum-1 == j)
			//	User_Request[i][j]=1;
		}

	}
}

unsigned long ulrand( ) {
    return (
     (((unsigned long)rand()<<24)&0xF0000ul)
    |(((unsigned long)rand()<<15)&0x0FF00ul)
    |(((unsigned long)rand()    )&0x000FFul));
}

//�û������������
void Request_Generator(int (& User_Request)[MaxUserNum][MaxFileNum])
{
	srand((unsigned)time(0)) ;
	for(int i=0;i<MaxUserNum;i++)
	{
        int temp = rand()%MaxFileNum;
		User_Request[i][temp]=1;		
	}
}

//���û����ļ�������Ϣ���������
void Out_Request(int (& User_Request)[MaxUserNum][MaxFileNum])
{
	ofstream file;
	file.open("�û�����-��0.0.txt");
	for(int i=0;i<MaxUserNum;i++)
	{
		for(int j=0;j<MaxFileNum;j++)
		{
			file<<User_Request[i][j]<<" ";
		}
		file<<endl;
	}
	file.close();
}

//�ӱ��ض�ȡ�ļ�������Ϣ
void Read_Request(int (& User_Request)[MaxUserNum][MaxFileNum])
{
	 ifstream file;
	 file.open("F:\\cache_state_3\\�û�����-��0.0.txt"); //���û����йأ���50���û����˴�Ϊcache_state_1�ļ����е��û�����-50.txt��
	 for(int i=0; i<MaxUserNum; i++)
	 {

		 for(int j=0; j<100; j++)
		 {
			 file>>User_Request[i][j];
		 }
	 }
}

void Print_Request(int *User_Request)
{
	cout<<"�û�����Ϊ "<<endl;
	for(int i=0;i<MaxUserNum;i++)
	{
		for(int j=0;j<MaxFileNum;j++)
		{
		    cout<<*(User_Request++)<<" ";
		}
		cout<<endl;		
	}
	cout<<endl;	
}