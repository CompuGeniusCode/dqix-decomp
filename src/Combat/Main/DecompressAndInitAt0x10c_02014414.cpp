#include <globaldefs.h>
#include "Graphics/LightingInfo.h"
#include "Memory/SafeAllocator.h"

void* DecompressLZ77FileIntoScratchSpace(SafeAllocator& alloc, const void* src, unsigned int& outSize);

// USA: func_02014414
extern "C" ARM int _ZN6Zone3D15ProcessBATSFileEPKvj(char* obj, const void* src) {
    SafeAllocator* alloc = *(SafeAllocator**)(obj + 0x68);
    unsigned int size;
    void* data = DecompressLZ77FileIntoScratchSpace(*alloc, src, size);
    ((LightingInfo*)(obj + 0x10c))->Initialize();
    ((LightingInfo*)((int)(obj + 0x10c)))->LoadFromScript((const void*)((int)data), (unsigned int)((int)size), (SafeAllocator*)((int)alloc));
    return 1;
}
