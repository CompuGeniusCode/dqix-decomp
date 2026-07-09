#include <globaldefs.h>

struct BitFlags02037180 {
    unsigned char pad0[0x40];
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
};

// USA: func_02037180
ARM int GetByte0x40Bit2(struct BitFlags02037180* obj) {
    return obj->b2;
}
