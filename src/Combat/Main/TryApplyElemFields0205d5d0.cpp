#include <globaldefs.h>

struct Elem0205d5d0 {
    char pad[0xc4];
    unsigned char fieldC4;
};

struct StructA0205d5d0 {
    char pad0[0x98];
    int field98;
    Elem0205d5d0* field9c;
    char pad2[0x13];
    unsigned char countB3;
};

int CheckField0x9cSetWhenField0xd4Present(unsigned char* obj);
void ApplyElemFields0205d904(unsigned char* obj);
extern "C" void func_0204cb20(void* elem, int c, int d, unsigned char e);

// USA: func_0205d5d0
ARM int TryApplyElemFields0205d5d0(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e) {
    Elem0205d5d0* elem;
    unsigned char i;

    if (c == 0) return 1;
    if (a->field98 == 0) return 1;
    if (a->field9c == 0) return 1;

    for (i = 0; i < a->countB3; i++) {
        elem = (Elem0205d5d0*)((char*)a->field9c + i * 0xe0);
        if (!CheckField0x9cSetWhenField0xd4Present((unsigned char*)elem)) continue;
        if (b != elem->fieldC4) continue;
        func_0204cb20(elem, c, d, e);
        ApplyElemFields0205d904((unsigned char*)a);
        return 0;
    }
    return 1;
}
