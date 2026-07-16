#include <globaldefs.h>
#include "System/Memory.h"

// USA: func_ov027_021dd3cc
void ClearRegion0x20_021dd3cc(void* obj) {
	VectorizedMemset(obj, 0, 0x20);
}
