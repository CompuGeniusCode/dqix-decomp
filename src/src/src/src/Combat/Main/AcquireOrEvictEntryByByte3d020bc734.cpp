#include <globaldefs.h>
#include "Memory/SignedAllocator.h"

struct Obj020bc6fc;
void DispatchType2Command020bc6fc(struct Obj020bc6fc* obj);
void InsertSortedByByte3dGlobal020bc6a8(SignedAllocatorHeader* what);

extern SignedAllocatorList data_0210f3cc;
extern SignedAllocatorList data_0210f3d8;

// USA: func_020bc734
ARM SignedAllocatorHeader* AcquireOrEvictEntryByByte3d020bc734(int target) {
    SignedAllocatorHeader* e = data_0210f3cc.ElementAfter(NULL);
    if (e == NULL) {
        e = data_0210f3d8.ElementAfter(NULL);
        if (target < *((unsigned char*)e + 0x3d)) {
            return NULL;
        }
        DispatchType2Command020bc6fc((struct Obj020bc6fc*)e);
    }
    data_0210f3cc.Remove(e);
    *((unsigned char*)e + 0x3d) = target;
    InsertSortedByByte3dGlobal020bc6a8(e);
    return e;
}
