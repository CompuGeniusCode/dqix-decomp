#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern unsigned int data_ov023_021fd6d4[10];

// USA: func_ov023_021e4f64
ARM void CreateTenAndOne_021e4f64(void* obj, SafeAllocator* src) {
    for (int i = 0; i < 10; i++) {
        unsigned int size = data_ov023_021fd6d4[i];
        void* buf = src->Allocate(size);
        ((SafeAllocator*)((char*)obj + 0x6b8 + i * 0x14))->CreateTypeA(buf, size);
    }
    void* buf = src->Allocate(0x1000);
    ((SafeAllocator*)((char*)obj + 0x780))->CreateTypeA(buf, 0x1000);
}
