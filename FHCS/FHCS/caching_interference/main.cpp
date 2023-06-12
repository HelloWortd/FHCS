//#include "Node.h"
#include "Fix_Cache.h"
#include "Request.h"
//ȫ�ֱ���
 	//�ڵ��ھӾ������ڱ�ʾ�ڵ��Ƿ�Ϊ�ھ�
	int NodeNeighborTable[MaxRelayNum][MaxUserNum];	
	//��¼�����û��Ĵ���ģʽ
	int Mode_Table[Mode_Num][MaxRelayNum]; 
	//��ʽϵ������
	//int Matrix_equation[equation_num][variable_num];
	//����ʽϵ������
	int Matrix_inequality[inequality_num][variable_num];
	//ln,i
	int Cache_State[MaxRelayNum][MaxFileNum];
 void main()
{
	
	int NodeNum=MAX_NODENUM;

	//�ڵ����飺�û��洢�ڵ�   P.S.:ǰMaxRelayNum����ʾ��վ����Ŀ����MaxUserNum����ʾ�û�����Ŀ
	Node Nodesarray[MAX_NODENUM];
	//�����ڵ�
	//NodesGenerator(NodeNum,Nodesarray);        
   
	//���ڵ�����д�뵽�����ĵ�
    // Node_write(NodeNum,Nodesarray);
	//�ӱ����ĵ��ж�ȡ�ڵ�����
	 Node_read(NodeNum, Nodesarray);

	//���������Ľڵ�
	//print_node(NodeNum,Nodesarray);

	//�ļ��ܻ�ӭ��
	double File_Pro[MaxFileNum] = {0.0};
	Pro_Generator(File_Pro);
	//Print_Pro(File_Pro);
	Out_Pro(File_Pro);
	//�û�����
	int User_Request[MaxUserNum][MaxFileNum]={0};
	//���ļ��ܻ�ӭ�Ȳ���
	//Request_Generator(User_Request, File_Pro);
	//�������
	//Request_Generator(User_Request);
	//���ļ�������Ϣд�뵽�����ĵ�
	//Out_Request(User_Request);
	//�ӱ����ĵ��ж�ȡ�ļ�������Ϣ
	Read_Request(User_Request);
	//Print_Request(User_Request[0]);

 	//�ڵ��ھӾ������ڱ�ʾ�ڵ��Ƿ�Ϊ�ھ�
	//int NodeNeighborTable[MaxRelayNum][MaxUserNum];	
	//���relay�ڵ��ھӱ�:�д���ͬ��relay�ڵ㣻�д���ͬ���û��ڵ�
	GetNodeNeighborTable(NodeNeighborTable[0],Nodesarray);
	//��ʾ�ڵ��ھӱ�
	//Print_NodeNeighborTable(NodeNeighborTable[0]);
	Out_NodeNeighborTable(NodeNeighborTable);

	//UserRelayTable ��¼��ÿ���û��������ӵĻ�վ����Ŀ
	int UserRelayArray[MaxUserNum] = {0};
	Get_UserRelayArray(NodeNeighborTable,UserRelayArray);
	//Print_UserRelayArray(UserRelayArray);

	//�õ�����ģʽ�ľ���
	//int Mode_Table[Mode_Num][MaxRelayNum]; 
	int User_Mode_Num[MaxUserNum];     //��¼ÿ���û����ڵĴ���ģʽ�ĸ���
	int Mode_Num_Real=Get_Mode_Table(NodeNeighborTable,Nodesarray,UserRelayArray,Mode_Table,User_Mode_Num);
	//Print_Mode_Table(Mode_Table,Mode_Num_Real);

		
	//������ÿһ�ִ���ģʽ���û��˿ɴ������,������������������
	double Rate[Mode_Num]={0.0};
	Get_Rate(Rate,Mode_Num_Real,Mode_Table,User_Mode_Num,Nodesarray,NodeNeighborTable);
	Out_Rate(Rate,Mode_Num_Real);
	//Out_Cache(variable_number,Mode_Num_Real);

	//ln,i������֪�����ܻ�ӭ�Ȼ��棬���������
	//Cache_Generator(Cache_State);    
	//����ӱ����ļ��ж�ȡ
	 Cache_read(Cache_State);
	//��ʾ��վ����״̬
	//Print_CacheState(Cache_State);                                  //��ʾ����״̬
	Calculate_LNI( Cache_State, NodeNeighborTable, User_Request );   //����Ŀ�꺯���еڶ����ֵ��������ln,i��֪ʱ�������Ƕ�ֵ

    const int variable_number=Get_variable_number(User_Mode_Num);  //��ѧģ����ʵ�ʵı�������
	int Objective_function[variable_num]={0};                      //Ŀ�꺯��

	//���Ŀ�꺯����Objective_function		
	Get_Objective_function(Objective_function,NodeNeighborTable,User_Request,Mode_Table,Mode_Num_Real,User_Mode_Num);
	Print_Objective_function(Objective_function,variable_number);

	//�����ʽ����ϵ����Matrix_equation
	//int Matrix_equation[equation_num][variable_num];
	//int equation_number = Mode_Num_Real*SubcarrierNum;
	//Get_Matrix_equation(Matrix_equation, Mode_Table, Mode_Num_Real,equation_number);
	//Print_Matrix_equation(Matrix_equation,equation_number,variable_number);
	
	//�������ʽ����ϵ����Matrix_inequality 	
	//int Matrix_inequality[inequality_num][variable_num];
	int Matrix_inequality_value[inequality_num];         // ����ʽ����ֵ
    const int inequality_number=Get_Matrix_inequality(Mode_Table,Matrix_inequality_value,Mode_Num_Real,User_Mode_Num,NodeNeighborTable,Rate, Matrix_inequality);
    Print_Matrix_inequality(Matrix_inequality_value,inequality_number,variable_number, Matrix_inequality);
	
  //getchar();
}










