#include <globaldefs.h>

struct Inner_0223d354 { unsigned char pad[0x32]; unsigned short field32; };
struct Outer_0223d354 { unsigned char pad[4]; struct Inner_0223d354* inner; };
extern struct Outer_0223d354 data_ov031_02290d40;

// USA: func_ov031_0223d354
ARM int CheckMaskAgainstField32_0223d354(int mask) {
	int v = *(unsigned short*)0x27fffa8 & 0x8000;
	if (v >> 15) {
		return 0;
	}
	int f = data_ov031_02290d40.inner->field32;
	int w = mask & f;
	return (mask == w) ? 1 : 0;
}
