#include <globaldefs.h>

extern "C" void _Z16SetInnerByte0x41P13Outer020bc158h(void* p, unsigned char v);
extern void* data_ov031_02290d00;

// USA: func_ov031_0223689c
extern "C" ARM void func_ov031_0223689c(unsigned char val) {
	_Z16SetInnerByte0x41P13Outer020bc158h((char*)data_ov031_02290d00 + 0x94, val);
}
