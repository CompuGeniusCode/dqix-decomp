#include <globaldefs.h>
#include "Memory/SignedAllocator.h"

void ClearFlagBit020bbef8(int bit);
extern SignedAllocatorList data_0210fca8;

struct Actor020bccf0 {
    char pad0[0x24];
    int field24;        /* 0x24 */
    char pad28[0x18];
    int field40;        /* 0x40 */
};

// USA: func_020bccf0
ARM void UnregisterActorFromGlobalList020bccf0(struct Actor020bccf0* obj) {
    ClearFlagBit020bbef8(obj->field40);
    data_0210fca8.Remove((SignedAllocatorHeader*)obj);
    obj->field24 &= ~1;
}
