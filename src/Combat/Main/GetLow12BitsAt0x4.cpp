#include <globaldefs.h>

struct S020797e8 {
    int pad0;
    unsigned int f : 12;
};

// USA: func_020797e8
ARM int GetLow12BitsAt0x4(struct S020797e8* p) {
    return p->f;
}
