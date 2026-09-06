#include <globaldefs.h>

int GetGlobalField0x1c020421a0();

// USA: func_ov001_0215e514  (semantic: SetGlobalFlagBit_0215e514)
extern "C" ARM int func_ov001_0215e514(void) {
    int r = GetGlobalField0x1c020421a0();
    if (r == 0) return 0;
    *(unsigned char*)(r + 0x1000 + 0x95b) |= 0x40;
    return 1;
}
