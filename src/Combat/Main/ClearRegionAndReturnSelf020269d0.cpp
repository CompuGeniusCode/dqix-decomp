#include <globaldefs.h>
#include "World/LootableContainer.h"


// USA: func_020269d0
ARM char* ClearRegionAndReturnSelf020269d0(char* obj) {
    ((LootableContainerManager*)(obj))->Reset();
    return obj;
}
