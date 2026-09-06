#include <globaldefs.h>

extern "C" void func_ov023_021dcba4(void* obj, int val);
extern "C" void func_ov023_021dcae0(void* obj, int val);

// USA: func_ov005_021551fc
ARM void DispatchByIdxAndCond021551fc(char* base, unsigned char byteVal, int cond) {
	signed char idx = *(signed char*)(base + 0x3d00 + 0xbb);
	short val = *(short*)(base + idx * 0x1c + 0x2d00 + 0x90);
	*(unsigned char*)(base + 0x1000 + 0x9be) = byteVal;
	unsigned short* flagPtr = (unsigned short*)(base + 0x1900 + 0xb8);
	*flagPtr = *flagPtr | 0x80;
	if (cond != 0) {
		func_ov023_021dcba4(base + 0x244 + 0x1000, val);
	} else {
		func_ov023_021dcae0(base + 0x244 + 0x1000, val);
	}
}
