#include <globaldefs.h>
#include "Memory/SignedAllocator.h"

extern SignedAllocatorList data_0210f3d8;

// USA: func_020bc6a8
ARM void InsertSortedByByte3dGlobal020bc6a8(SignedAllocatorHeader* what) {
    SignedAllocatorHeader* e = data_0210f3d8.ElementAfter(NULL);
    if (e != NULL) {
        do {
            if (*((unsigned char*)what + 0x3d) < *((unsigned char*)e + 0x3d)) break;
            e = data_0210f3d8.ElementAfter(e);
        } while (e != NULL);
    }
    data_0210f3d8.InsertBefore(e, what);
}
