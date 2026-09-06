#include <globaldefs.h>

struct Obj02088818;
void SetStateAndByte0x6a(struct Obj02088818* obj, unsigned short mode);

struct StateWrapObj020886dc {
    unsigned char pad00[0x18];
    unsigned int flags18;
};

// USA: func_020886dc
ARM void SetCombatantState1(struct StateWrapObj020886dc* obj) {
    obj->flags18 |= 0x80;
    SetStateAndByte0x6a((struct Obj02088818*)obj, 1);
}
