#include <globaldefs.h>
#include "World/ZoneFeatures.h"
#include "System/Memory.h"

// USA: func_0201e248
extern "C" ARM void _ZN12ZoneFeatures5ResetEv(void* obj) {
    VectorizedMemset(obj, 0, 0x88);
}
