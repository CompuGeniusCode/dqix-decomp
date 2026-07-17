#include <globaldefs.h>

extern "C" void func_ov031_0221ae00(void*);

// USA: func_ov031_0221c3f8
ARM void Init_0221c3f8(char *dest) {
	char buf[0x14];
	func_ov031_0221ae00(buf);
	*(unsigned long long*)(dest + 0) = *(unsigned long long*)(buf + 0);
	*(unsigned long long*)(dest + 8) = *(unsigned long long*)(buf + 8);
	int w4 = *(int*)(buf + 4);
	int w0 = *(int*)(buf + 0);
	int r = 0;
	if (w4 != 0 || w0 != 0) r = 1;
	*(int*)(dest + 0x10) = r;
}
