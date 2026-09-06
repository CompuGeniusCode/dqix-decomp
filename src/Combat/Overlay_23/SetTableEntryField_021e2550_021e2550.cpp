#include <globaldefs.h>

extern "C" void* func_ov023_021e2418(void* obj);
ARM void* GetTableEntry020421b0(int idx);

struct Obj021e2550 {
    char pad0[0xc];
    void* field0xc;
};

// USA: func_ov023_021e2550  (semantic: SetTableEntryField_021e2550_021e2550)
extern "C" ARM void* func_ov023_021e2550(void* obj, int unused, int index) {
    struct Obj021e2550* e = (struct Obj021e2550*)func_ov023_021e2418(obj);
    if (!e) return e;
    void* entry = GetTableEntry020421b0((index * 4 + 0x28) & 0xff);
    e->field0xc = entry;
    return entry;
}
