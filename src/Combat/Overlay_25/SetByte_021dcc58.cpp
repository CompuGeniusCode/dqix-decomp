#include <globaldefs.h>

// USA: func_ov025_021dcc58
ARM void SetByte_021dcc58(void* obj, unsigned char v) {
	unsigned char* base = (unsigned char*)obj;
	(base + 0x6000)[0xe4b] = v;
}
