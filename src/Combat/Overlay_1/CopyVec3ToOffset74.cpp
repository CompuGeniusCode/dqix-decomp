#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_ov001_0215929c
ARM int CopyVec3ToOffset74(void* a, void* b) {
	memcpy((char*)b + 0x74, (char*)a + 4, 0xc);
	return 0;
}
