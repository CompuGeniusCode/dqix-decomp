#include <globaldefs.h>

// USA: func_ov006_021553a8
ARM void SetFlag8_021553a8(void* p) {
	unsigned short* f = (unsigned short*)((char*)p + 0xa00 + 0xe2);
	*f = *f | 8;
}
