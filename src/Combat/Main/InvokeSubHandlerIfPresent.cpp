#include <globaldefs.h>

extern "C" int _Z21FreeVRAMStagingMemoryPKv(int);

// USA: func_020e2478
ARM int InvokeSubHandlerIfPresent(int* obj) {
    int p = obj[0];
    if (p == 0) return p;
    return _Z21FreeVRAMStagingMemoryPKv(p);
}
