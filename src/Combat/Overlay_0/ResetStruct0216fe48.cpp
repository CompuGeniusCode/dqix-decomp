#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct0216fe48 {
	int f0;
	unsigned char pad0[0x84 - 0x4];
	int f84;
	unsigned char f88[0x18];
	unsigned char f0xa0;
	unsigned char f0xa1;
};

// USA: func_ov000_0216fe48
ARM void ResetStruct0216fe48(struct Struct0216fe48* obj) {
	obj->f0 = -1;
	obj->f84 = 0;
	obj->f0xa0 = 0;
	obj->f0xa1 = 0;
	memset(obj->f88, 0, 0x18);
}
