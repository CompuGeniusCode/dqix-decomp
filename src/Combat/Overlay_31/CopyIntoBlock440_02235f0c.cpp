#include <globaldefs.h>
#include "System/Memory.h"

struct Struct02235f0c { unsigned char* field0; };
extern struct Struct02235f0c data_ov031_02290cfc;

// USA: func_ov031_02235f0c  (semantic: CopyIntoBlock440_02235f0c)
extern "C" ARM void func_ov031_02235f0c(void* src) {
	VectorizedInvertedMemcpy(data_ov031_02290cfc.field0 + 0x440, src, 0x20);
}
