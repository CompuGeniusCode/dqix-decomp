#include <globaldefs.h>

struct Inner020e28dc {
    char pad[0x3f];
    unsigned char flag : 1;
};

struct Outer020e28dc {
    char pad[0xc];
    struct Inner020e28dc* inner;
};

// USA: func_020e28dc
ARM int GetInnerFlagBit0020e28dc(struct Outer020e28dc* o) {
    return o->inner->flag;
}
