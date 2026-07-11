#include <globaldefs.h>

struct Obj020ccba8;
void SetPendingFlagIfActive020ccba8(struct Obj020ccba8*);
extern "C" void func_020d970c();
extern "C" void func_020d974c();

struct Slot020d8d20 {
    unsigned short h0;
    unsigned short h2;
};

// USA: func_020d8d20
ARM int MarkSlotReadyUnderGuard020d8d20(struct Slot020d8d20* slot) {
    int result = 0;
    func_020d970c();
    if (slot->h0 == 1) {
        SetPendingFlagIfActive020ccba8((struct Obj020ccba8*)((char*)slot + 4));
        result = 1;
    }
    slot->h2 = 1;
    func_020d974c();
    return result;
}
