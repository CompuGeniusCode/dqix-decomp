#include <globaldefs.h>

extern "C" void func_0204c804(void* p);

struct Elem0207fe44 { char b[0xe0]; };

struct Cont0207fe44 {
    char pad0[0x30];
    Elem0207fe44* elems;
    char pad34[0x39 - 0x34];
    unsigned char count39;
};

// USA: func_0207fe44
ARM void CallFunc0204c804OverAllElems(Cont0207fe44* obj) {
    unsigned char count;
    Elem0207fe44* p = obj->elems;
    unsigned char i;
    if (p == NULL) return;
    count = obj->count39;
    for (i = 0; i < count; i++) {
        func_0204c804(p);
        p++;
    }
}
