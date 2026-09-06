#include <globaldefs.h>

struct S021fb8cc { char pad[0xa4]; unsigned short fieldA4; };

// USA: func_ov023_021fb8cc  (semantic: SetFieldA4_021fb8cc)
extern "C" ARM void func_ov023_021fb8cc(struct S021fb8cc *obj, unsigned short v) {
	obj->fieldA4 = v;
}
