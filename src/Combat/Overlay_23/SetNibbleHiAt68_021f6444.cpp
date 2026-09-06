#include <globaldefs.h>

struct Obj021f6444 {
	char pad[0x44];
	unsigned char field;
};

// USA: func_ov023_021f6444
ARM void SetNibbleHiAt68_021f6444(struct Obj021f6444 *obj, unsigned int v) {
	obj->field = (obj->field & ~0xf0) | ((v & 0xf) << 4);
}
