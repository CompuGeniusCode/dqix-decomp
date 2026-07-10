#include <globaldefs.h>

unsigned int DisableInterrupts();
unsigned int RestoreInterrupts(unsigned int mask);

struct Sub020ccba8 {
    char pad[0x1c];
    unsigned int f1c;
};

struct Obj020ccba8 {
    char pad[8];
    struct Sub020ccba8* sub;
    unsigned int flags;
};

// USA: func_020ccba8
ARM void SetPendingFlagIfActive020ccba8(struct Obj020ccba8* obj) {
    unsigned int mask = DisableInterrupts();
    int active = (obj->flags & 1) != 0;
    if (active) {
        obj->flags |= 2;
        obj->sub->f1c |= 0x20;
    }
    RestoreInterrupts(mask);
}
