#include <globaldefs.h>

void* SetGlobalContext02110370(void* value);
// _Z24CallFunc020bc548OnField0Pv is a trampoline decompiled with a 1-arg signature but actually
// forwards a 2nd arg (r1) through its bx tail-call; reference its mangled symbol
// directly so the required `mov r1` is emitted while resolving to the real symbol.
extern "C" void* _Z24CallFunc020bc548OnField0Pv(void* obj, int arg);

// USA: func_0203acc8
ARM void ForwardToTargetOrDefault0203acc8(void* obj, void* target, int arg) {
    if (*(int*)obj == 0) return;
    SetGlobalContext02110370((char*)obj + 4);
    if (target != NULL) {
        _Z24CallFunc020bc548OnField0Pv(target, arg);
    } else {
        _Z24CallFunc020bc548OnField0Pv((char*)obj + 0x98, arg);
    }
}
