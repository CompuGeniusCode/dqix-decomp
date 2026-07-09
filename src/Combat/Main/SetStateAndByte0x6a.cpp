#include <globaldefs.h>

struct Obj02088818 {
    unsigned char pad00[0x22];
    unsigned short : 9;
    unsigned short state : 3;
    unsigned short : 4;
    unsigned char pad24[0x6a - 0x24];
    unsigned char byte6a;
    unsigned char pad6b[0x8d - 0x6b];
    unsigned char byte8d;
};

// USA: func_02088818
ARM void SetStateAndByte0x6a(struct Obj02088818* obj, unsigned short mode) {
    obj->state = mode;
    obj->byte6a = 5;
    obj->byte8d = 0;
}
