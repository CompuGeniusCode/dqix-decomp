#include <globaldefs.h>

void* GetActiveCombatWork(void);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

struct Inner021e8748 {
    unsigned int v[3];
};

struct Obj021e8748 {
    char pad[8];
    struct Inner021e8748 mid;
};

// USA: func_ov025_021e8748  (semantic: SyncCombatantVecToWork_021e8748)
extern "C" ARM int func_ov025_021e8748(struct Obj021e8748* obj) {
    void* w = GetActiveCombatWork();
    if (w) {
        struct Inner021e8748 local = obj->mid;
        _ZN8Vector3iaSERKS_((int*)((char*)w + 0x6fdc), (int*)&local);
        *((char*)w + 0x6fe8) = 1;
    }
    return 1;
}
