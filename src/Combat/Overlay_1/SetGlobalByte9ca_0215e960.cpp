#include <globaldefs.h>

int GetGlobalField0x1c020421a0();

// USA: func_ov001_0215e960  (semantic: SetGlobalByte9ca_0215e960)
extern "C" ARM int func_ov001_0215e960(void) {
    *(unsigned char*)(GetGlobalField0x1c020421a0() + 0x1000 + 0x9ca) = 0;
    return 1;
}
