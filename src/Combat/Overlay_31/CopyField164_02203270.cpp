#include <globaldefs.h>

extern void* data_02111304;

// USA: func_ov031_02203270
ARM void CopyField164_02203270(void* obj) {
	void* p = *((void**)&data_02111304 + 1);
	*(int*)((char*)obj + 0xa4) = *(int*)((char*)p + 0xa4);
}
