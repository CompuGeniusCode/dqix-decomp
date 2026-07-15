#include <globaldefs.h>

struct Obj_021b04c0 {
	char pad0[0xa];
	unsigned char fieldA;
	char pad1[0x21 - 0xb];
	unsigned char field21;
	unsigned char field22;
	char pad2[0x28 - 0x23];
	int field28;
};

// USA: func_ov017_021b04c0
ARM unsigned char ResetOrGetFieldA_021b04c0(Obj_021b04c0* obj) {
	if (obj->field28 != 0) {
		obj->field21 = 0;
		obj->field22 = 0;
		return 7;
	}
	return obj->fieldA;
}
