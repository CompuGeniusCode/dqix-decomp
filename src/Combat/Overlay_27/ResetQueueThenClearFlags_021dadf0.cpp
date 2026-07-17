#include <globaldefs.h>

void ClearFlagsTo_021dae1c_021dae1c(void);

struct ResetFields021dadf0 {
	char pad0[0x14];
	int f14;
	int f18;
	int f1c;
	char pad1[0x24 - 0x20];
	unsigned char f24;
};

extern ResetFields021dadf0 data_ov027_021dd940;

// USA: func_ov027_021dadf0
ARM void ResetQueueThenClearFlags_021dadf0(void) {
	data_ov027_021dd940.f18 = 0;
	data_ov027_021dd940.f1c = 0;
	data_ov027_021dd940.f24 = 1;
	data_ov027_021dd940.f14 = 0;
	ClearFlagsTo_021dae1c_021dae1c();
}
