#include <globaldefs.h>

extern "C" void func_ov023_021dced4(void* p, unsigned char v);

// USA: func_ov006_021571b8
ARM void SetByte_021571b8_021571b8(void* p, unsigned char v) {
	func_ov023_021dced4((char*)p + 0x2e4 + 0x800, v);
}
