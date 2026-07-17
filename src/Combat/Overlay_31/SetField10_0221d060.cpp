#include <globaldefs.h>

struct DataE6e0_0221d060 {
	unsigned char pad0[0x10];
	unsigned int field10;
};

extern DataE6e0_0221d060 data_ov031_0224e6e0;

// USA: func_ov031_0221d060
ARM void SetField10_0221d060(unsigned int value) {
	data_ov031_0224e6e0.field10 = value;
}
