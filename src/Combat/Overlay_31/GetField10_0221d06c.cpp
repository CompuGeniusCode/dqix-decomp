#include <globaldefs.h>

struct DataE6e0_0221d06c {
	unsigned char pad0[0x10];
	unsigned int field10;
};

extern DataE6e0_0221d06c data_ov031_0224e6e0;

// USA: func_ov031_0221d06c
ARM unsigned int GetField10_0221d06c(void) {
	return data_ov031_0224e6e0.field10;
}
