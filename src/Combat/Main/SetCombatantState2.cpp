#include <globaldefs.h>

struct Obj02088818;
void SetStateAndByte0x6a(struct Obj02088818* obj, unsigned short mode);

struct StateWrapObj02088724 {
    unsigned char pad00[0x18];
    unsigned int flags18;
};

// USA: func_02088724
ARM void SetCombatantState2(struct StateWrapObj02088724* obj) {
    obj->flags18 |= 0x80;
    SetStateAndByte0x6a((struct Obj02088818*)obj, 2);
}
