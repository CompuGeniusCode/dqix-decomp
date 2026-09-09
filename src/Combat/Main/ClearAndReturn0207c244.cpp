#include <globaldefs.h>
#include "World/LootableContainer.h"


// USA: func_0207c244
extern "C" ARM char* _ZN24LootableContainerManagerC1Ev(char* obj) {
    ((LootableContainerManager*)(obj))->Reset();
    return obj;
}
