#include <globaldefs.h>

struct Coords020de7a4 {
    unsigned short a;
    unsigned short idx : 15;
    unsigned short flag : 1;
};

// USA: func_020de7a4
ARM int ComputeOffsetFromFields(struct Coords020de7a4* obj) {
    int idx = obj->idx;
    int a = obj->a;
    int base = obj->flag ? 0x58 : 0;
    return base + idx * 32 + a * 32;
}
