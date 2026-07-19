#include <globaldefs.h>

struct Inner_0223d3d4 { unsigned char pad[0x36]; unsigned short field36; };
struct Outer_0223d3d4 { unsigned char pad[4]; struct Inner_0223d3d4* inner; };
extern struct Outer_0223d3d4 data_ov031_02290d40;

// USA: func_ov031_0223d3d4
ARM int CheckMaskAgainstField36_0223d3d4(int mask) {
	int v = *(unsigned short*)0x27fffa8 & 0x8000;
	if (v >> 15) {
		return 0;
	}
	int f = data_ov031_02290d40.inner->field36;
	int w = mask & f;
	return (mask == w) ? 1 : 0;
}
