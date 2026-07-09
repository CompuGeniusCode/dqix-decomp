#include <globaldefs.h>

struct Obj02088674 {
    unsigned char pad00[0x18];
    unsigned int flags18;
    unsigned char pad1c[6];
    unsigned short : 9;
    unsigned short state : 3;
    unsigned short : 4;
    unsigned char pad24[0x6a - 0x24];
    unsigned char byte6a;
    unsigned char pad6b[0x8d - 0x6b];
    unsigned char byte8d;
};

// USA: func_02088674
ARM void ResetFlag0x80AndState(struct Obj02088674* obj) {
    obj->flags18 &= ~0x80;
    obj->state = 0;
    obj->byte6a = 0;
    obj->byte8d = 0;
}
