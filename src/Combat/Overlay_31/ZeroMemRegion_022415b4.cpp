#include <globaldefs.h>
#include "System/Memory.h"

// USA: func_ov031_022415b4
ARM void ZeroMemRegion_022415b4(void* obj, unsigned int len) {
	VectorizedMemset(obj, 0, len);
}
