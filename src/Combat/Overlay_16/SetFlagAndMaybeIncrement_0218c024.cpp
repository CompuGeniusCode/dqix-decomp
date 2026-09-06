#include <globaldefs.h>

struct S0218c024 {
	char pad0[0x4];
	int flag4;      // 0x4
	char pad1[0x38 - 0x8];
	int flag38;     // 0x38
	int counter3c;  // 0x3c
};

extern S0218c024 data_ov016_0219d0c0;

// USA: func_ov016_0218c024
ARM void SetFlagAndMaybeIncrement_0218c024(void) {
	data_ov016_0219d0c0.flag4 = 1;
	if (data_ov016_0219d0c0.flag38 == 0) data_ov016_0219d0c0.counter3c++;
}
