#include <globaldefs.h>

struct Obj0218ef2c { char pad0[0x20]; void* p20; void* pad1; void* p28; };

// USA: func_ov016_0218ef2c
ARM int GetFlagValue_0218ef2c(struct Obj0218ef2c* o) {
	if (o->p20 == NULL) return 0;
	return o->p28 != NULL ? 0x80 : 0x100;
}
