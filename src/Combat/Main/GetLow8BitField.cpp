#include <globaldefs.h>

struct S020797f8 {
    unsigned int f : 8;
};

// USA: func_020797f8
ARM int GetLow8BitField(struct S020797f8* p) {
    return p->f;
}
