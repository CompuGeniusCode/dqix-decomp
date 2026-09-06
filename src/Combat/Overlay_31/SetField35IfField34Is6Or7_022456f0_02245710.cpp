#include <globaldefs.h>

struct Obj_022456f0 { unsigned char pad34[0x34]; unsigned char f34; unsigned char f35; };
ARM int SetField35IfField34Is6Or7_022456f0(Obj_022456f0* obj);

// USA: func_ov031_02245710
extern "C" ARM int func_ov031_02245710(Obj_022456f0* obj, int arg1) {
	if (arg1 != 0) return SetField35IfField34Is6Or7_022456f0(obj);
	if (obj->f34 == 6) {
		if (obj->f35 == 2 || obj->f35 == 1) return SetField35IfField34Is6Or7_022456f0(obj);
	}
	return 0;
}
