#include <globaldefs.h>

struct Obj_021d4a24;
void ClearFields3c_40_44_021d4a24(Obj_021d4a24* obj);

struct Obj021d49d0 {
	int f0;
	int f4;
	unsigned char pad1[4];
	int fc;
	int f10;
	int f14;
	int f18;
	unsigned char pad2[4];
	int f20;
	int f24;
	int f28;
	int f2c;
	unsigned char pad3[8];
	int f38;
	unsigned char pad4[4];
	int f40;
};

// USA: func_ov017_021d49d0
ARM Obj021d49d0* SetupObj_021d49d0(Obj021d49d0* obj) {
	obj->f14 = obj->f10;
	obj->f18 = obj->f10;
	obj->f28 = obj->f24;
	obj->f2c = obj->f24;
	obj->f38 = 0;
	obj->f4 = 0;
	obj->fc = 0;
	obj->f20 = 0;
	obj->f40 = 0;
	obj->f0 = 1;
	ClearFields3c_40_44_021d4a24((Obj_021d4a24*)obj);
	return obj;
}
