#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

void* DecompressLZ77FileIntoScratchSpace(SafeAllocator& alloc, const void* src, unsigned int& outSize);
extern "C" void _ZN12ZoneFeatures5ResetEv(void* obj);
extern "C" void _ZN12ZoneFeatures14LoadFromScriptEP13SafeAllocatorPKvj(int a, int b, int c, int d);

// USA: func_02014390
extern "C" ARM int _ZN6Zone3D15ProcessBMBLFileEPKvj(char* obj, const void* src) {
    SafeAllocator* alloc = *(SafeAllocator**)(obj + 0x68);
    unsigned int size;
    void* data = DecompressLZ77FileIntoScratchSpace(*alloc, src, size);
    int saved = *(int*)(obj + 0x8);
    _ZN12ZoneFeatures5ResetEv(obj + 0x6c);
    _ZN12ZoneFeatures14LoadFromScriptEP13SafeAllocatorPKvj((int)(obj + 0x6c), (int)alloc, (int)data, (int)size);
    *(int*)(obj + 0x8) = saved;
    return 1;
}
