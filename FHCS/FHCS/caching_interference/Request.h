
#include "Function.h"

//文件的受欢迎度
void Pro_Generator(double *p);
void Print_Pro(double *p);
void Out_Pro(double (& Pro)[MaxFileNum]);

//用户请求按文件受欢迎度产生
void Request_Generator(int (& User_Request)[MaxUserNum][MaxFileNum],double *File_Pro);

//用户请求随机产生
void Request_Generator(int (& User_Request)[MaxUserNum][MaxFileNum]);


//将文件请求信息写入到本地文档
void Out_Request(int (& User_Request)[MaxUserNum][MaxFileNum]);

//从本地文档中读取用户请求
void Read_Request(int (& User_Request)[MaxUserNum][MaxFileNum]);

void Print_Request(int *User_Request);