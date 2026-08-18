#include <globaldefs.h>

struct Struct_0205d81c;
struct Elem_0205d81c {
    char pad0[0xa8];
    short f_a8;
    char pad1[2];
    short f_ac;
    short f_ae;
};
struct Elem_0205d81c* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);
extern "C" void func_0205ac40(void* a, void* b);

struct Obj0218aee4 {
    char pad0[0x1f4];
    void* f1f4;
    char* f1f8;
    char pad1[0xe99 - 0x1fc];
    signed char flagE99;
};

// USA: func_ov008_0218aee4
extern "C" ARM void UpdateExtentFromElem_0218aee4(struct Obj0218aee4* obj) {
    if (obj->flagE99 != 1) return;
    struct Elem_0205d81c* e = FindElementByC40205d81c((struct Struct_0205d81c*)((char*)obj + 0x18), 0);
    if (e == 0) return;

    short ac = e->f_ac;
    short ae = e->f_ae;
    char* p = obj->f1f8;

    short sac = ac << 3;
    int baseA = sac - 1;
    short sae = ae << 3;
    int baseB = sae - 1;
    short a8 = e->f_a8;
    *(int*)(p + 0x104) = baseA << 12;
    *(int*)(p + 0x108) = baseB << 12;
    func_0205ac40(obj->f1f4, p + 0xf0);

    short sa8 = a8 << 3;
    p = obj->f1f8;
    *(int*)(p + 0x12c) = (sac + sa8 - 8) << 12;
    *(int*)(p + 0x130) = (sae - 1) << 12;
    func_0205ac40(obj->f1f4, p + 0x118);
}
