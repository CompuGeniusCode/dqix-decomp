#include <globaldefs.h>
#include "Graphics/AtmosphericEffect.h"
#include "Graphics/NSBXX/NSBXX.h"

struct Obj0207a6a4;

extern "C" void _ZN20AtmosphericEffectSet14ProcessArchiveEPS_P13SafeAllocatorPv(void* a, void* b, int c, int d);

extern "C" int _ZN7Model3D7GetTEX0Ev(void* obj);

// USA: func_0201498c
ARM int AccumulateHandleStats0201498c(void* objRaw) {
    unsigned char* obj = (unsigned char*)objRaw;
    struct Obj0207a6a4* handle = (struct Obj0207a6a4*)(obj + 0xf4);

    if (!((AtmosphericEffectSet*)(handle))->IsArchiveLoaded()) {
        return 0;
    }

    _ZN20AtmosphericEffectSet14ProcessArchiveEPS_P13SafeAllocatorPv(handle, handle, *(int*)(obj + 0x68), *(int*)(obj + 0x50));

    void* node = (void*)(int)((AtmosphericEffectSet*)((int*)handle))->GetFirstEffect();
    while (node != NULL) {
        void* p = *(void**)((char*)node + 0x8);
        if (p != NULL) {
            int val = _ZN7Model3D7GetTEX0Ev(p);
            if (val != 0) {
                *(int*)(obj + 0x838) += NSBXX_Tex_GetBlock1Length((NSBXXTex*)val);
                *(int*)(obj + 0x83c) += (int)NSBXX_Tex_GetBlock4Length((NSBXXTex*)val);
            }
        }
        node = *(void**)((char*)node + 0x100);
    }
    return 1;
}
