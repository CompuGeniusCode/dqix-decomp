#include <globaldefs.h>

struct InitStruct0208a9c0Data;
void InitStruct0208a9c0(struct InitStruct0208a9c0Data* p, unsigned char a, unsigned char b, unsigned char c);

struct S0208aa18;
void SetVec3At0xC(struct S0208aa18* s, int x, int y, int z);

struct Obj0208af78 {
    char pad0[0x94];
    unsigned char arr94[4];
    unsigned char arr98[4];
    unsigned char f9c;
    char pad1[0xb];
    unsigned char fa8;
    char pad2[3];
    int fac;
    int fb0;
};

// USA: func_0208af78  (semantic: InitObjectSlots0208af78)
extern "C" ARM void func_0208af78(struct Obj0208af78* obj) {
    InitStruct0208a9c0((struct InitStruct0208a9c0Data*)((char*)obj + 0x4), 0, 1, 0x50);
    InitStruct0208a9c0((struct InitStruct0208a9c0Data*)((char*)obj + 0x24), 0, 1, 0x14);
    InitStruct0208a9c0((struct InitStruct0208a9c0Data*)((char*)obj + 0x40), 1, 5, 0x14);
    InitStruct0208a9c0((struct InitStruct0208a9c0Data*)((char*)obj + 0x5c), 2, 5, 0x14);
    InitStruct0208a9c0((struct InitStruct0208a9c0Data*)((char*)obj + 0x78), 3, 3, 0x14);

    SetVec3At0xC((struct S0208aa18*)((char*)obj + 0x4), 0x1f, 0, 0x14);
    SetVec3At0xC((struct S0208aa18*)((char*)obj + 0x24), 0x1f, 0, 0x14);
    SetVec3At0xC((struct S0208aa18*)((char*)obj + 0x40), 0x1c, 0x1c, 0);
    SetVec3At0xC((struct S0208aa18*)((char*)obj + 0x5c), 0x1c, 0x1c, 0);
    SetVec3At0xC((struct S0208aa18*)((char*)obj + 0x78), 0x19, 0, 0);

    unsigned char v = 0x28;
    int i;
    for (i = 0; i < 4; i++) {
        obj->arr94[i] = v;
        obj->arr98[i] = v;
    }

    obj->f9c = 0;
    obj->fa8 = 0;
    obj->fb0 = 0;
    obj->fac = -1;
}
