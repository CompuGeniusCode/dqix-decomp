#include <globaldefs.h>

struct S021fd45c { char pad[0x2a]; unsigned short field2a; };

// USA: func_ov023_021fd45c  (semantic: SetField2a_021fd45c)
extern "C" ARM void func_ov023_021fd45c(struct S021fd45c *obj, unsigned short v) {
	obj->field2a = v;
}
