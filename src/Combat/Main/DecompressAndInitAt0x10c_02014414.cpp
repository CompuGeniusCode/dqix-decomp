#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

void* DecompressLZ77FileIntoScratchSpace(SafeAllocator& alloc, const void* src, unsigned int& outSize);
void Init0207b98c(char* obj);
int ForwardReordered0207ba0c(int a, int b, int c, int d);

// USA: func_02014414
ARM int DecompressAndInitAt0x10c_02014414(char* obj, const void* src) {
    SafeAllocator* alloc = *(SafeAllocator**)(obj + 0x68);
    unsigned int size;
    void* data = DecompressLZ77FileIntoScratchSpace(*alloc, src, size);
    Init0207b98c(obj + 0x10c);
    ForwardReordered0207ba0c((int)(obj + 0x10c), (int)data, (int)size, (int)alloc);
    return 1;
}
