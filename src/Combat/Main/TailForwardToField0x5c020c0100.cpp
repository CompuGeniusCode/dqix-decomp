#include <globaldefs.h>

struct Obj020ccba8;
int SetPendingFlagIfActive020ccba8(struct Obj020ccba8*);

// USA: func_020c0100
ARM int TailForwardToField0x5c020c0100(void* obj) {
    return SetPendingFlagIfActive020ccba8((struct Obj020ccba8*)((char*)obj + 0x5c));
}
