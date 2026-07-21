#include <globaldefs.h>

struct BoxParam_0223d634 { unsigned short x, y, w, h; };
struct RangeParam_0223d634 { unsigned short f0, f1, f2, f3; };

extern "C" int func_ov031_0223d49c(struct RangeParam_0223d634* p);

// USA: func_ov031_0223d634  (semantic: CheckBoxInBoundsFlag1_0223d634)
#pragma optimize_for_size off
extern "C" ARM int func_ov031_0223d634(struct BoxParam_0223d634* box) {
	struct RangeParam_0223d634 range;
	int v = *(unsigned short*)0x27fffa8 & 0x8000;

	if (v >> 15) return 0;

	range.f0 = box->x;
	range.f1 = box->y;
	range.f2 = box->x + box->w;
	range.f3 = box->y + box->h;
	return func_ov031_0223d49c(&range);
}
