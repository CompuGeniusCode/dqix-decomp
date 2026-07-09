#include <globaldefs.h>

struct Bits41_37474 {
    char unk0[0x41];
    unsigned char lo5 : 5;
    unsigned char hi3 : 3;
};

// USA: func_02037474
ARM int GetField0x41Bits0To4(struct Bits41_37474* obj) {
    return obj->lo5;
}
