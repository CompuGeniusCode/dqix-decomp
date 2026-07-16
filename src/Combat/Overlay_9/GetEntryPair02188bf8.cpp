#include <globaldefs.h>

struct Entry02188bf8 { short a, b, c, d, e; };
extern struct Entry02188bf8 data_ov009_0218aa70[];

// USA: func_ov009_02188bf8
ARM void GetEntryPair02188bf8(unsigned char *base, int idx, short *out0, short *out1) {
	int i2 = *(unsigned char*)(base + 0xda3);
	struct Entry02188bf8 *e = (struct Entry02188bf8*)((char*)data_ov009_0218aa70 + i2 * 20);
	*out0 = *(short*)((char*)e + idx * 4);
	*out1 = *(short*)((char*)e + idx * 4 + 2);
}
