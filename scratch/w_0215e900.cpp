#include <globaldefs.h>

int GetGlobalField0x1c020421a0();

// USA: func_ov001_0215e900
ARM int SetGlobalBytes9c0_95d_0215e900(void) {
    int r = GetGlobalField0x1c020421a0();
    *(unsigned char*)(r + 0x1000 + 0x9c0) = 1;
    *(unsigned char*)(r + 0x1000 + 0x95d) = 0x1e;
    return 1;
}
