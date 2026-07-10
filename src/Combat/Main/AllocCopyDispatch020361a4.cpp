#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

extern "C" void func_02036200(void*, int, SafeAllocator*, void*, unsigned int);

// USA: func_020361a4
ARM void AllocCopyDispatch020361a4(void* a, int b, SafeAllocator* alloc, void* src, unsigned int size) {
    void* buf = alloc->Allocate(size);
    if (buf != NULL) {
        memcpy(buf, src, size);
        func_02036200(a, b, alloc, buf, size);
    }
}
