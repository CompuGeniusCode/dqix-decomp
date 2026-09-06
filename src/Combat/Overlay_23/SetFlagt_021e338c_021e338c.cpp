#include <globaldefs.h>

// USA: func_ov023_021e338c
ARM void SetFlagt_021e338c_021e338c(char* p) {
	unsigned short* flags = (unsigned short*)(p + 0x600 + 0x34);
	*flags = *flags | 0x1000;
}
