#include <globaldefs.h>
#include "System/Memory.h"

int IsGlobal0224e5a4Set_02211aec(void);
extern "C" int func_ov031_0223f264(void*, void*, int);

// USA: func_ov031_02212c3c
ARM int InitAndProcessArray_02212c3c(void* buf, void* b, int count) {
	if (IsGlobal0224e5a4Set_02211aec()) return 0;
	VectorizedMemset(buf, 0, count * 0xb0);
	return func_ov031_0223f264(buf, b, count);
}
