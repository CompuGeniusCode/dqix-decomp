#include <globaldefs.h>

struct Vec3 { int x, y, z; };
extern "C" void CopyVec3(int* dst, int* src);

struct Obj02033874;
extern "C" void SetVecYFromValue02033874(struct Obj02033874* obj, int arg);

struct Ctx02049e00 {
    char pad[0x10];
    int field10;
    int field14;
    int field18;
    char pad1c[0x20 - 0x1c];
    unsigned int flags;
};

#define CTX02049E00(o) (*(Ctx02049e00**)((char*)(o) + 0x13c))

extern Vec3 data_020e7b24;

// USA: func_02049e00
ARM void ApplyContextVectorAndFlags02049e00(void* obj) {
    Ctx02049e00* ctx = CTX02049E00(obj);
    if (ctx != 0) {
        ctx->flags &= ~0x22;
        Vec3 v;
        unsigned int f = CTX02049E00(obj)->flags | 1;
        v = data_020e7b24;
        CTX02049E00(obj)->flags = f;
        v.x = CTX02049E00(obj)->field10;
        v.z = CTX02049E00(obj)->field18;
        int angle = CTX02049E00(obj)->field14;
        CopyVec3((int*)((char*)obj + 0x44), (int*)&v);
        SetVecYFromValue02033874((struct Obj02033874*)obj, angle);
    }
}
