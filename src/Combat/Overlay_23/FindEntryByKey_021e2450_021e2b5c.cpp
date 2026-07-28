#include <globaldefs.h>

struct Container_021e27f8;

struct Obj021e2b5c {
    char pad0[8];
    int f8;
    int fc;
    char pad10[4];
    unsigned short f14;
    unsigned short f16;
};

ARM void* FindEntryByKey_021e2450(void* obj, int val);
ARM void* FindEntryContaining_021e27f8(struct Container_021e27f8* obj, int key);
extern "C" void func_ov023_021e2acc(void* obj, int val, short* out1, short* out2);

// USA: func_ov023_021e2b5c  (semantic: LookupAndDispatchEntry_021e2b5c)
extern "C" ARM void func_ov023_021e2b5c(struct Obj021e2b5c* obj, int key, short* out1, short* out2) {
    if (obj->f8 == 0 || obj->f14 == 0 || obj->fc == 0 || obj->f16 == 0) return;
    void* e = FindEntryByKey_021e2450(obj, key);
    if (!e) return;
    *out1 = *(short*)((char*)e + 4);
    *out2 = *(short*)((char*)e + 6);
    void* e2 = FindEntryContaining_021e27f8((struct Container_021e27f8*)obj, key);
    if (!e2) return;
    short v = *(short*)e2;
    func_ov023_021e2acc(obj, v, out1, out2);
}
