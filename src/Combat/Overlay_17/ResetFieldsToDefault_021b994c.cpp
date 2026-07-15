#include <globaldefs.h>

struct Obj_021b994c {
	char pad[0x12c];
	unsigned int field12c;
	unsigned char field130;
	unsigned char field131;
	unsigned char field132;
	char pad2[0x136 - 0x133];
	unsigned char field136;
};

// USA: func_ov017_021b994c
ARM void ResetFieldsToDefault_021b994c(Obj_021b994c* obj) {
	obj->field12c = -1;
	obj->field130 = 0;
	obj->field131 = 0;
	obj->field132 = 0;
	obj->field136 = 0;
}
