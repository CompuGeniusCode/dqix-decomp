#include <globaldefs.h>

struct Field_ccf7c {
    unsigned int ptr : 24;
    unsigned int flags : 8;
};

struct S_ccf7c {
    char pad0[0x8];
    void* f8;
    char padc[0x10];
    struct Field_ccf7c f1c;
};

// USA: func_020ccf7c
ARM void* GetTaggedPointer0x1c(struct S_ccf7c* p) {
    if (p->f1c.flags & 1) {
        return (void*)p->f1c.ptr;
    }
    return p->f8;
}
