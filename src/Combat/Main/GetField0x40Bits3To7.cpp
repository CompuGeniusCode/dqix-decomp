#include <globaldefs.h>

struct Bits40_37464 {
    char unk0[0x40];
    unsigned char lo3 : 3;
    unsigned char hi5 : 5;
};

// USA: func_02037464
ARM int GetField0x40Bits3To7(struct Bits40_37464* obj) {
    return obj->hi5;
}
