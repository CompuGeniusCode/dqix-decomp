#include <globaldefs.h>

// USA: func_ov017_02195530
ARM void SetFlag320_02195530(unsigned char* obj) {
	obj += 0x4000;
	*(int*)(obj + 0x320) = 1;
}
