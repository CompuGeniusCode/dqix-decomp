#include <globaldefs.h>

struct S021fbcb0 { char pad[0x36]; unsigned short field36; };

// USA: func_ov023_021fbcb0  (semantic: SetField36_021fbcb0)
extern "C" ARM void func_ov023_021fbcb0(struct S021fbcb0 *obj, unsigned short v) {
	obj->field36 = v;
}
