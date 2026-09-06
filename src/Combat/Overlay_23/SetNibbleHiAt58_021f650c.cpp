#include <globaldefs.h>

struct Obj021f650c {
	char pad[0x3a];
	unsigned char field;
};

// USA: func_ov023_021f650c
ARM void SetNibbleHiAt58_021f650c(struct Obj021f650c *obj, unsigned int v) {
	obj->field = (obj->field & ~0xf0) | ((v & 0xf) << 4);
}
