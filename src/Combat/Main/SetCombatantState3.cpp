#include <globaldefs.h>

struct Obj02088818;
void SetStateAndByte0x6a(struct Obj02088818* obj, unsigned short mode);

struct StateWrapObj0208876c {
    unsigned char pad00[0x18];
    unsigned int flags18;
};

// USA: func_0208876c
ARM void SetCombatantState3(struct StateWrapObj0208876c* obj) {
    obj->flags18 |= 0x80;
    SetStateAndByte0x6a((struct Obj02088818*)obj, 3);
}
