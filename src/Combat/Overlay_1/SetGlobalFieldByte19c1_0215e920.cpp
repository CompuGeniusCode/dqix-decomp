#include <globaldefs.h>

int GetGlobalField0x1c020421a0();

// USA: func_ov001_0215e920
ARM int SetGlobalFieldByte19c1_0215e920() {
    *(unsigned char*)(GetGlobalField0x1c020421a0() + 0x1000 + 0x9c1) = 1;
    return 1;
}
