#include <globaldefs.h>

struct Obj02088818;
void SetStateAndByte0x6a(struct Obj02088818* obj, unsigned short mode);

struct StateWrapObj020887b4 {
    unsigned char pad00[0x18];
    unsigned int flags18;
};

// USA: func_020887b4
ARM void SetCombatantState4(struct StateWrapObj020887b4* obj) {
    obj->flags18 |= 0x80;
    SetStateAndByte0x6a((struct Obj02088818*)obj, 4);
}
