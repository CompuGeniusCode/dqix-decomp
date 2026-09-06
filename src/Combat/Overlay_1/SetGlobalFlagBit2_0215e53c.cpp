#include <globaldefs.h>

int GetGlobalField0x1c020421a0();

// USA: func_ov001_0215e53c
ARM int SetGlobalFlagBit2_0215e53c(void) {
    int r = GetGlobalField0x1c020421a0();
    if (r == 0) return 0;
    *(unsigned char*)(r + 0x1000 + 0x95b) |= 2;
    return 1;
}
