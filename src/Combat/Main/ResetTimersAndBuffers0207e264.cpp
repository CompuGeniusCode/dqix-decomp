#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_0207e264
ARM void ResetTimersAndBuffers0207e264(unsigned char* self) {
    *(int*)(self + 0xa8) &= ~1;
    *(int*)(self + 0x54) = 0;
    *(int*)(self + 0x58) = 0;
    *(int*)(self + 0x5c) = 0;
    *(int*)(self + 0x9c) = 0;
    *(unsigned short*)(self + 0xa0) = 0x1000;
    *(int*)(self + 0x98) = 0;
    *(int*)(self + 0x90) = 0;
    *(int*)(self + 0x94) = 0;
    *(unsigned short*)(self + 0xa2) = 0x1f;
    *(int*)(self + 0xa8) &= ~2;
    *(int*)(self + 0xa8) &= ~4;
    *(short*)(self + 0xa4) = 0x1f - 0x20;
    *(short*)(self + 0xa6) = 0x1f - 0x20;
    memset(self, 0, 0x54);
    memset(self + 0x64, 0, 0x18);
}
