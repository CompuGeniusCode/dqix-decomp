#include <globaldefs.h>

struct FourShorts_0223cb1c { short field0; short field2; short field4; short field6; };

// USA: func_ov031_0223cb1c
ARM void FillFourShorts_0223cb1c(short a, short b, short c, short d, struct FourShorts_0223cb1c* out) {
	out->field0 = a;
	out->field2 = b;
	out->field4 = c;
	out->field6 = d;
}
