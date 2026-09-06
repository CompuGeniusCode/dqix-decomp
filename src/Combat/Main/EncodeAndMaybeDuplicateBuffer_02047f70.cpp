#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" int func_020bb7cc(unsigned int size, int a, int b);
extern "C" int _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(int a, int b, int c, int d, unsigned char e, unsigned char f);

struct Obj02047f70 {
    char pad0[0x10];
    int field10;
    char pad14[0x84 - 0x14];
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char bit3 : 1;
    unsigned char bit4 : 1;
    unsigned char bit5 : 1;
    unsigned char bit6 : 1;
    unsigned char bit7 : 1;
};

// USA: func_02047f70  (semantic: EncodeAndMaybeDuplicateBuffer_02047f70)
extern "C" ARM void func_02047f70(struct Obj02047f70* obj, void* buf, unsigned int size, SafeAllocator* allocator) {
    unsigned int computedSize = ((unsigned int)func_020bb7cc(size, 0, 0) << 16) >> 13;
    unsigned char usedOriginal = 1;
    if (obj->bit2 && allocator != NULL) {
        void* newBuf = allocator->Allocate(size);
        if (newBuf != NULL) {
            memcpy(newBuf, buf, size);
            buf = newBuf;
            usedOriginal = 0;
        }
    }
    _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(0, (int)buf, (int)computedSize, (int)size, 0, usedOriginal);
    obj->field10 = (int)computedSize;
}
