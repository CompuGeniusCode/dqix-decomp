#include <globaldefs.h>

struct Obj0215c300 { char unk[0x598]; int counter; };

// USA: func_ov003_0215c300
#pragma optimize_for_size off
ARM int DecrementFieldClampZero_0215c300(struct Obj0215c300* obj, int amount) {
    if (obj->counter > amount) {
        obj->counter -= amount;
    } else {
        obj->counter = 0;
        return 0;
    }
    return 1;
}
