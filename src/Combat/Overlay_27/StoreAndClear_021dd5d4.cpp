#include <globaldefs.h>
#include "System/Memory.h"

struct Field0x4Holder_021dd5d4 {
	unsigned char pad0[4];
	void* ptr;
};

extern Field0x4Holder_021dd5d4 data_ov027_021e3424;

// USA: func_ov027_021dd5d4
ARM void StoreAndClear_021dd5d4(void* obj) {
	data_ov027_021e3424.ptr = obj;
	VectorizedMemset(obj, 0, 0x21c);
}
