#include <globaldefs.h>

struct Inner0207e22c {
    int value;
};

struct Outer0207e22c {
    int unk0;
    struct Inner0207e22c* ptr;
};

// USA: func_0207e22c
ARM void StoreValueViaPtrField0x4(struct Outer0207e22c* s, int value) {
    struct Inner0207e22c* p = s->ptr;
    if (p != NULL) {
        p->value = value;
    }
}
