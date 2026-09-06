#include <globaldefs.h>

int GetGlobalField0x1c020421a0();

// USA: func_ov001_0215e564  (semantic: ClearGlobalByte9b2_0215e564)
extern "C" ARM int func_ov001_0215e564(void) {
    int r = GetGlobalField0x1c020421a0();
    if (r == 0) return 0;
    *(unsigned char*)(r + 0x1000 + 0x9b2) = 0;
    return 1;
}
