#include <globaldefs.h>

struct Elem0204bbb4 {
    char pad[0x10];
};

struct Obj0204bbb4 {
    char pad0[0x10];
    struct Elem0204bbb4* p10;
    char pad14[0x1d - 0x14];
    unsigned char count1d;
};

extern "C" void func_0204bab4(struct Obj0204bbb4*, struct Elem0204bbb4*, int, int, int, int, int, int, int);

// USA: func_0204bbb4
ARM void CallListEntry0204bbb4(struct Obj0204bbb4* obj, unsigned int idx, int a2, int a3,
                               short a4, short a5, short a6, short a7, unsigned short a8) {
    if (obj->count1d > idx && obj->p10 != NULL) {
        func_0204bab4(obj, &obj->p10[idx], a2, a3, a4, a5, a6, a7, a8);
    }
}
