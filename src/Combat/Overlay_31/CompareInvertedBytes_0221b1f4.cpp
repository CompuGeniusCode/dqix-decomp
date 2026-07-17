#include <globaldefs.h>
#include "System/Memory.h"

extern "C" int CheckRange_0221b258(unsigned char* p);

// USA: func_ov031_0221b1f4
#pragma optimize_for_size off
ARM int CompareInvertedBytes_0221b1f4(unsigned char* a, unsigned char* b) {
    if (!CheckRange_0221b258(a)) {
        return 0;
    }
    unsigned int la;
    unsigned int lb;
    VectorizedInvertedMemcpy(a, &la, 4);
    VectorizedInvertedMemcpy(b, &lb, 4);
    return (la & ~lb) != 0;
}
