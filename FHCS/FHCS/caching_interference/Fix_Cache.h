 #ifndef FIX_CACHE_H_
#define FIX_CACHE_H_
#include "Request.h"

//�����ļ��ܻ�ӭ�Ȳ�����վ���棬ln,i,�����������վ����
void Cache_Generator(int (& Cache_State)[MaxRelayNum][MaxFileNum]);

//�ӱ����ļ��ж�ȡ
void Cache_read(int (& Cache_State)[MaxRelayNum][MaxFileNum]);

//��ʾ����״̬
void Print_CacheState(int (& Cache_State)[MaxRelayNum][MaxFileNum]);

//����Ŀ�꺯���еڶ���ln,i��ֵ
void Calculate_LNI(int (& Cache_State)[MaxRelayNum][MaxFileNum], int (& NodeNeighborTable)[MaxRelayNum][MaxUserNum], int (& User_Request)[MaxUserNum][MaxFileNum] );

#endif
