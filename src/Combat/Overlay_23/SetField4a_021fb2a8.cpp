#include <globaldefs.h>

struct S021fb2a8 { char pad[0x4a]; unsigned char field4a; };

// USA: func_ov023_021fb2a8  (semantic: SetField4a_021fb2a8)
extern "C" ARM void func_ov023_021fb2a8(struct S021fb2a8 *obj, unsigned char v) {
	obj->field4a = v;
}
