#include <globaldefs.h>

extern char* data_ov004_02171010;
extern "C" void func_ov011_021848a0(void* obj, int val);

// USA: func_ov004_0216583c  (semantic: SetFieldByteAndFlag101_0216583c)
extern "C" ARM int func_ov004_0216583c(void* obj) {
	*(unsigned char*)(data_ov004_02171010 + 0x1000 + 0x8fd) = 1;
	func_ov011_021848a0(obj, 0x65);
	return 0;
}
