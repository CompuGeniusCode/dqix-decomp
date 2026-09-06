#include <globaldefs.h>

// USA: func_ov000_02160f20
ARM void* GetSlotPtr02160f20(void* obj) {
    void* base = *(void**)((char*)obj + 0x29c);
    void* cached;
    if (base == 0) return 0;
    cached = *(void**)((char*)obj + 0x7000 + 0x70c);
    if (cached == 0) {
        int count = *(int*)((char*)obj + 0x5000 + 0x5d8);
        cached = (char*)base + 0x21c + 0x8000 + count * 0x28;
    }
    return cached;
}
