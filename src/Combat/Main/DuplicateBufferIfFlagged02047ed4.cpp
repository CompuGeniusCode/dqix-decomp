#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" int func_020bb588(unsigned int size, int a, int b);
int EncodeStreamFields020dc0e0(int a, int b, int c, int d, unsigned char e, unsigned char f);

struct Obj02047ed4 {
    unsigned char pad[0x84];
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char bit3 : 1;
    unsigned char bit4 : 1;
    unsigned char bit5 : 1;
    unsigned char bit6 : 1;
    unsigned char bit7 : 1;
};

// USA: func_02047ed4
ARM void DuplicateBufferIfFlagged02047ed4(struct Obj02047ed4* obj, int* outSize, void* buf, unsigned int size, SafeAllocator* allocator) {
    int bits = func_020bb588(size, 0, 0);
    unsigned int computedSize = ((unsigned int)bits << 16) >> 13;
    unsigned char usedOriginal = 1;
    if (obj->bit2 && allocator != NULL) {
        void* newBuf = allocator->Allocate(size);
        if (newBuf != NULL) {
            memcpy(newBuf, buf, size);
            buf = newBuf;
            usedOriginal = 0;
        }
    }
    EncodeStreamFields020dc0e0(1, (int)buf, (int)computedSize, (int)size, 0, usedOriginal);
    *outSize = (int)computedSize;
}
