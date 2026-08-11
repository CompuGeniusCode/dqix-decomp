#include <globaldefs.h>

struct DispatchCtx021db124 {
	char pad0[0x1c];
	int f1c;
	char pad1[0x24 - 0x20];
	unsigned char f24;
	unsigned char f25pad;
	unsigned char f26;
};

extern DispatchCtx021db124 data_ov027_021dd940;

// USA: func_ov027_021db124  (semantic: PrepareCommandField_021db124)
extern "C" ARM void func_ov027_021db124(void) {
	*(unsigned short*)((unsigned char*)data_ov027_021dd940.f1c + 0x4b0) = 1;
	data_ov027_021dd940.f26 = ((unsigned char*)data_ov027_021dd940.f1c)[0x4b4];
	data_ov027_021dd940.f24 = 5;
}
