#include <globaldefs.h>
#include "System/Memory.h"

struct Struct02235cac { unsigned char* field0; };
extern struct Struct02235cac data_ov031_02290cfc;

// USA: func_ov031_02235cac
ARM void CopyBlockAndClearFlag_02235cac(void* p) {
	VectorizedInvertedMemcpy(p, data_ov031_02290cfc.field0 + 0x440, 0x20);
	data_ov031_02290cfc.field0[0x4e7] = 0;
}
