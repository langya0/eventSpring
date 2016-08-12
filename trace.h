#include <stdio.h>

#ifndef __NOTRACE
#define Trace(...) printf("file[%s]func[ %s ]line[ %d ]#", __FILE__,__func__, __LINE__);printf(__VA_ARGS__);printf("\n");

#else
#define Trace(...)
#endif