#include <globaldefs.h>

struct S0218fcac {
	int f0;    // 0x0
	int f4;    // 0x4
	char pad0[0xc - 0x8];
	int fc;    // 0xc
	int f10;   // 0x10
	char pad1[0x20 - 0x14];
	int f20;   // 0x20
};

extern S0218fcac data_ov016_0219d1c0;

// USA: func_ov016_0218fcac
ARM void SetupHandle_0218fcac(void* h, int mask) {
	data_ov016_0219d1c0.f10 = (int)h;
	data_ov016_0219d1c0.fc = mask & ~3;
	data_ov016_0219d1c0.f4 = 0;
	data_ov016_0219d1c0.f0 = 0;
	data_ov016_0219d1c0.f20 = 0;
}
