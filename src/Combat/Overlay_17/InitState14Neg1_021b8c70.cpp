#include <globaldefs.h>

struct Obj_021b8c70 { unsigned char b0; unsigned char pad[7]; int w8; };

// USA: func_ov017_021b8c70
ARM void InitState14Neg1_021b8c70(Obj_021b8c70* obj) {
	obj->b0 = 0xe;
	obj->w8 = 0xe - 0xf;
}
