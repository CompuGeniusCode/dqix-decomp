#include <globaldefs.h>

extern "C" void func_02083c48(void*);

struct T0205420c {
    char pad[0x150];
    void* field150;
};

// USA: func_0205420c
ARM void MaybeCall0205420c(struct T0205420c* obj) {
    void* p = obj->field150;
    if (p != NULL) func_02083c48(p);
}
