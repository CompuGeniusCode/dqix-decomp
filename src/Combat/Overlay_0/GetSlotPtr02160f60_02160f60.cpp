#include <globaldefs.h>

#pragma optimize_for_size off
// USA: func_ov000_02160f60
ARM void* GetSlotPtr02160f60(void* obj) {
    int count = *(int*)((char*)obj + 0x5000 + 0x5d8);
    if (count == 0) return 0;
    void* base = *(void**)((char*)obj + 0x29c);
    if (base == 0) return 0;
    return (char*)base + 0x21c + 0x8000 + (count - 1) * 0x28;
}
