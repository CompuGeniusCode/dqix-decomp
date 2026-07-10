#include <globaldefs.h>
#include "Memory/SignedAllocator.h"

// USA: func_020bdbe0
ARM void InitAllocatorListZero(SignedAllocatorList* list) {
    list->Initialize(0);
}
