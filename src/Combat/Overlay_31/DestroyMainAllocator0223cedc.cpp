#include <globaldefs.h>
#include "Memory/HPXEAllocator.h"

extern HPXEAllocator* data_ov031_02290d3c;

// USA: func_ov031_0223cedc
ARM void DestroyMainAllocator0223cedc(void) {
    data_ov031_02290d3c->RemoveFromTree();
    data_ov031_02290d3c = NULL;
}
