#include <globaldefs.h>

extern void* data_02111304;

// USA: func_ov031_02203250
ARM void ZeroField164_02203250(void) {
	void* p = *((void**)&data_02111304 + 1);
	int* q = *(int**)((char*)p + 0xa4);
	if (q) *q = 0;
}
