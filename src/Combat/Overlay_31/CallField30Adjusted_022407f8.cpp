#include <globaldefs.h>

struct Sub022407f8 { unsigned char pad[0xc]; int fieldC; unsigned char pad2[8]; int field18; };
struct Obj022407f8 { unsigned char pad[0x30]; struct Sub022407f8* sub; };

extern "C" int func_ov031_02241480(void*, int, int, int, int);

// USA: func_ov031_022407f8
ARM int CallField30Adjusted_022407f8(struct Obj022407f8* obj, int b, int c, int d) {
	struct Sub022407f8* sub = obj->sub;
	return func_ov031_02241480(obj, b, sub->field18 + c, sub->fieldC - c, d);
}
