#include <globaldefs.h>

extern "C" void func_ov023_021e5628(void* obj, void* ctx);
extern "C" void _ZN8Object3D4DrawEb(void* obj, int flag);

// USA: func_ov009_02184c30  (semantic: SyncCombatantAndFlushMatrix_02184c30)
extern "C" ARM void func_ov009_02184c30(void* objRaw) {
    char* obj = (char*)objRaw;
    signed char id = *(signed char*)(obj + 0xc58);
    if (id == 0 || id == 0xc) {
        return;
    }

    *(int*)0x4000444 = 0;
    func_ov023_021e5628(*(void**)(obj + 0x7f8), 0);

    if (*(int*)(obj + 0xd9c) & 0x200) {
        _ZN8Object3D4DrawEb(obj + 0x878, 1);
        _ZN8Object3D4DrawEb(obj + 0xcd8, 1);
    }

    *(int*)0x4000448 = 1;
}
