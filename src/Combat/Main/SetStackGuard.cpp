#include <globaldefs.h>

// USA: func_020c7a74
ARM void SetStackGuard(void* t, int size) {
    *(int*)((char*)t + 0x98) = size;
    if (size != 0) {
        void* base = *(void**)((char*)t + 0x90);
        *(unsigned int*)((char*)base + size) = 0x597dfbd9;
    }
}
