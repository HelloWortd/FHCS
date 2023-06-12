 #ifndef FIX_CACHE_H_
#define FIX_CACHE_H_
#include "Request.h"

//按照文件受欢迎度产生基站缓存，ln,i,或随机产生基站缓存
void Cache_Generator(int (& Cache_State)[MaxRelayNum][MaxFileNum]);

//从本地文件中读取
void Cache_read(int (& Cache_State)[MaxRelayNum][MaxFileNum]);

//显示缓存状态
void Print_CacheState(int (& Cache_State)[MaxRelayNum][MaxFileNum]);

//计算目标函数中第二项ln,i的值
void Calculate_LNI(int (& Cache_State)[MaxRelayNum][MaxFileNum], int (& NodeNeighborTable)[MaxRelayNum][MaxUserNum], int (& User_Request)[MaxUserNum][MaxFileNum] );

#endif
