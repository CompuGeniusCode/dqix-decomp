#include <globaldefs.h>

// USA: _Z20GetDataTcmRegionBasev
ARM unsigned int GetDataTcmRegionBase(void) {
    unsigned int v;
    asm {
        mrc p15, 0, v, c9, c1, 0
    }
    v = v & 0xfffff000;
    return v;
}
