#include <globaldefs.h>

extern "C" void* func_ov000_02161318(void* obj, int id);
int GetClampedArrayField0xd3c(char* base, int index);

// USA: func_ov000_02162b90
ARM void ProcessSlot_02162b90(void* self, int unused1, int c, int unused3, int compareVal, signed char idx6, signed char p2) {
    int flags = *(int*)((char*)self + 0x5000 + 0x5f4);
    if (!(flags & 0x10000)) {
        return;
    }
    if (flags & 0x800000) {
        return;
    }
    int bestIdx = -1;
    int i = 0;
    while (i < 12) {
        int val = GetClampedArrayField0xd3c((char*)self + 0x760 + 0x3000, i);
        if (compareVal == val) {
            bestIdx = i;
            break;
        }
        i++;
    }
    void* entry = func_ov000_02161318((char*)self + 0x760 + 0x3000, idx6);
    if (entry != NULL) {
        *(short*)((char*)entry + 0x26) = (short)c;
        *(unsigned char*)((char*)entry + 0x1d) = (unsigned char)bestIdx;
        *(unsigned char*)((char*)entry + 0x2e) = (unsigned char)p2;
    }
}
