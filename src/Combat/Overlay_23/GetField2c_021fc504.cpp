#include <globaldefs.h>

struct S021fc504 { char pad[0x2c]; unsigned short field2c; };

// USA: func_ov023_021fc504
ARM unsigned short GetField2c_021fc504(struct S021fc504 *obj) {
	return obj->field2c;
}
