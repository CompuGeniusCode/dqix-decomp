#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

void ShiftInBitOnGlobalObject(void);
void HalveGlobalObjectCounter(void);
void* LoadFileIntoMemory(const char*, void*, unsigned int*);

extern "C" void func_02036200(void* a, void* b, SafeAllocator* alloc, void* buf, unsigned int size);

extern char data_0211e33c[];

// USA: func_02036120  (semantic: AllocateAndDispatchFile02036120)
extern "C" ARM void func_02036120(void* a, void* b, const char* name, SafeAllocator* alloc) {
    if (name != NULL) {
        ShiftInBitOnGlobalObject();
        unsigned int outSize;
        void* loaded = LoadFileIntoMemory(name, data_0211e33c, &outSize);
        if (loaded != NULL) {
            unsigned int size = outSize;
            void* buf = alloc->Allocate(size);
            if (buf != NULL) {
                memcpy(buf, data_0211e33c, size);
                func_02036200(a, b, alloc, buf, size);
            }
        }
        HalveGlobalObjectCounter();
    }
}
