
#include "Function.h"

//�ļ����ܻ�ӭ��
void Pro_Generator(double *p);
void Print_Pro(double *p);
void Out_Pro(double (& Pro)[MaxFileNum]);

//�û������ļ��ܻ�ӭ�Ȳ���
void Request_Generator(int (& User_Request)[MaxUserNum][MaxFileNum],double *File_Pro);

//�û������������
void Request_Generator(int (& User_Request)[MaxUserNum][MaxFileNum]);


//���ļ�������Ϣд�뵽�����ĵ�
void Out_Request(int (& User_Request)[MaxUserNum][MaxFileNum]);

//�ӱ����ĵ��ж�ȡ�û�����
void Read_Request(int (& User_Request)[MaxUserNum][MaxFileNum]);

void Print_Request(int *User_Request);