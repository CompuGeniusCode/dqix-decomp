#include <globaldefs.h>

int IsNotInList0224e22c_02207180(void* v);
extern "C" int func_ov031_02207970(void* obj, void* v);

struct Obj022078f0 {
	char pad0[0x70];
	short field70;
	char pad72;
	signed char field73;
};

// USA: func_ov031_022078f0
ARM int Validate_022078f0(Obj022078f0* obj, void* v) {
	if (IsNotInList0224e22c_02207180(obj)) {
		return ~0x1b;
	}
	signed char f = obj->field73;
	int match = 1;
	if (f != 0) {
		if (f != 4) {
			match = 0;
		}
	}
	if (!match) {
		return ~0x1b;
	}
	int ok = 0;
	if (obj == NULL) goto checkOk;
	if (!(obj->field70 & 1)) goto checkOk;
	ok = 1;
checkOk:
	if (!ok) {
		return ~0x26;
	}
	if (*(volatile short*)&obj->field70 & 2) {
		return ~0x1b;
	}
	return func_ov031_02207970(obj, v);
}
