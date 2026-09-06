#include <globaldefs.h>

struct Struct0218bc9c { char pad1[8]; int flags; char pad2[0xa2]; unsigned char fae; };

// USA: func_ov015_0218bc9c
ARM int GetFieldOrDefault0218bc9c(struct Struct0218bc9c* s) {
	if (s->flags & 0x10) return s->fae;
	return -1;
}
