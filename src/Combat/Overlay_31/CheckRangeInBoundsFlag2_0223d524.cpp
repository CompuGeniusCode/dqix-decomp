#include <globaldefs.h>

struct Inner_0223d524 {
	unsigned char pad[0x28];
	unsigned short min;
	unsigned short max;
	unsigned char pad2[0xc];
	unsigned char flag0:1, flag1:1, flag2:1, flag3:1, flag4:1, flag5:1, flag6:1, flag7:1;
};
struct Outer_0223d524 { unsigned char pad[4]; struct Inner_0223d524* inner; };
extern struct Outer_0223d524 data_ov031_02290d40;

struct RangeParam_0223d524 { unsigned short f0, f1, f2, f3; };

// USA: func_ov031_0223d524  (semantic: CheckRangeInBoundsFlag2_0223d524)
extern "C" ARM int func_ov031_0223d524(struct RangeParam_0223d524* p) {
	int v = *(unsigned short*)0x27fffa8 & 0x8000;
	if (v >> 15) return 0;
	struct Inner_0223d524* in = data_ov031_02290d40.inner;
	if (!in->flag2) return 0;
	unsigned short min = in->min;
	if (p->f0 > min) return 0;
	if (p->f2 < min) return 0;
	unsigned short max = in->max;
	if (p->f1 > max) return 0;
	return (p->f3 >= max) ? 1 : 0;
}
