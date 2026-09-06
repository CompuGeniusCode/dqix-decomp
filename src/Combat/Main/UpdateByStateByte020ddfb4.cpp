#include <globaldefs.h>

struct ClampField020ddffc;
void AdvanceClampedField0x18(struct ClampField020ddffc* obj);
struct Struct020de0c8;
void DecrementField0x18020de0c8(struct Struct020de0c8* obj);
extern "C" void func_020de038(void* obj);

struct StateObj020ddfb4 {
    unsigned char pad[4];
    unsigned char state;
};

// USA: func_020ddfb4
ARM void UpdateByStateByte020ddfb4(struct StateObj020ddfb4* obj) {
    unsigned char state = obj->state;
    if (state == 2) {
        AdvanceClampedField0x18((struct ClampField020ddffc*)obj);
        return;
    }
    if (state == 1) return;
    if (state == 3) {
        func_020de038(obj);
        return;
    }
    if (state != 4) return;
    DecrementField0x18020de0c8((struct Struct020de0c8*)obj);
}
