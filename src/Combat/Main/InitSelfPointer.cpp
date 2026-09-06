#include <globaldefs.h>

// USA: func_02042b1c
ARM void InitSelfPointer(unsigned char* base) {
    *(unsigned char**)(base + 0x1e20) = base + 0x914;
}
