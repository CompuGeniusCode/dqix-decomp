#include <globaldefs.h>

struct State0204166c;
void Forward020416c0(struct State0204166c* s);

ARM bool IsHighByteFF02044494(void* obj, void* src);

struct StateEntry0206b198 {
    char pad0[8];
    int field8;
    char pad1[0x1c - 0xc];
};

struct CombatSlots0206b198 {
    char pad0[0x9b4];
    int field9b4;
    StateEntry0206b198 stateArr[0x80];
    unsigned char byteArr[0x80];
};

// USA: func_0206b198
ARM void DecrementSlotRef0206b198(struct CombatSlots0206b198* obj, unsigned short idx) {
    if (idx >= 0x80) return;
    if (IsHighByteFF02044494(obj, &idx)) return;
    struct StateEntry0206b198* e = &obj->stateArr[idx];
    if (e->field8 < 0) return;
    if (obj->byteArr[idx] == 0) return;
    int cnt = obj->byteArr[idx] - 1;
    obj->byteArr[idx] = cnt;
    if ((cnt & 0xff) != 0) return;
    Forward020416c0((struct State0204166c*)e);
    obj->field9b4 = (obj->field9b4 - 1) & 0x7f;
}
