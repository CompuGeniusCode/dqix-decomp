#include <globaldefs.h>

extern "C" void func_0204c8f0(void* p);

struct Elem0205d228 { char b[0xe0]; };

struct Cont0205d228 {
    char pad0[0x98];
    void* list98;
    Elem0205d228* list9c;
    char padA0[0x13];
    unsigned char countB3;
};

// USA: func_0205d228
ARM void CallFunc0204c8f0OverList0x9c(Cont0205d228* obj) {
    unsigned char i;
    if (obj->list98 == NULL || obj->list9c == NULL) return;
    for (i = 0; i < obj->countB3; i++) {
        func_0204c8f0(&obj->list9c[i]);
    }
}
