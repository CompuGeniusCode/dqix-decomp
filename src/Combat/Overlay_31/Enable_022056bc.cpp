#include <globaldefs.h>

extern "C" int IsNotInList0224e22c_02207180(void* v);
extern "C" int func_ov031_02205814(void* obj);

struct Obj022056bc {
	char pad[0x70];
	short field70;
	char pad2[0x1];
	signed char field73;
	unsigned short field74;
};

// USA: func_ov031_022056bc
ARM int Enable_022056bc(Obj022056bc* obj, unsigned short val) {
	if (IsNotInList0224e22c_02207180(obj)) return ~0x1b;
	int cond = 0;
	if (obj == 0) goto check2;
	if (obj->field70 & 1) cond = 1;
check2:
	if (!cond) return ~0x26;
	if (obj->field70 & 2) return ~0x6;
	obj->field74 = val;
	if (obj->field73 != 1) return 0;
	return func_ov031_02205814(obj);
}
