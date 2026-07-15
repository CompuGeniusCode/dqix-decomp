#include <globaldefs.h>

struct Elem020d7638;
void DispatchReadyCombatantSlots(struct Elem020d7638* obj);
extern "C" void func_020d7534(void* p);

// USA: func_ov000_02160c60
ARM void ProcessSlot02160c60(void* work) {
    void* p = *(void**)((char*)work + 0xea4);
    if (p) {
        func_020d7534(p);
        DispatchReadyCombatantSlots((struct Elem020d7638*)*(void**)((char*)work + 0xea4));
    }
}
