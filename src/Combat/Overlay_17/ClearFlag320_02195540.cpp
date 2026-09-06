#include <globaldefs.h>

// USA: func_ov017_02195540
ARM void ClearFlag320_02195540(unsigned char* obj) {
	obj += 0x4000;
	*(int*)(obj + 0x320) = 0;
}
