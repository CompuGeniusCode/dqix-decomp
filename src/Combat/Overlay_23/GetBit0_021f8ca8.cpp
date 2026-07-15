#include <globaldefs.h>

struct Obj021f8ca8 {
	char pad[0x45];
	unsigned char flag : 1;
	unsigned char rest : 7;
};

// USA: func_ov023_021f8ca8
ARM int GetBit0_021f8ca8(struct Obj021f8ca8 *obj) {
	return obj->flag != 0;
}
