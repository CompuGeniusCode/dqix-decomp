#include <globaldefs.h>
#include "System/Memory.h"

// USA: func_ov027_021dd104
void ClearRegion0x70_021dd104(void* obj) {
	VectorizedMemset(obj, 0, 0x70);
}
