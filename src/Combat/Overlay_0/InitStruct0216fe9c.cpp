#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_ov000_0216fe9c  (semantic: InitStruct0216fe9c)
extern "C" ARM void func_ov000_0216fe9c(char* obj) {
    *(unsigned short*)(obj + 0x0) = 1;
    *(unsigned short*)(obj + 0x2) = 1;
    *(unsigned short*)(obj + 0x4) = 1;
    *(unsigned short*)(obj + 0x6) = 1;
    memset(obj + 0x8, 0, 8);
    *(unsigned char*)(obj + 0x8) = 0xd;
    int z = 0;
    *(unsigned char*)(obj + 0x10) = z;
    *(unsigned char*)(obj + 0x11) = z;
    *(unsigned char*)(obj + 0x13) = z;
    int negOne = z - 1;
    *(char*)(obj + 0x14) = negOne;
    *(char*)(obj + 0x15) = negOne;
    *(char*)(obj + 0x18) = negOne;
    *(short*)(obj + 0x16) = negOne;
    *(char*)(obj + 0x19) = negOne;
    *(char*)(obj + 0x1a) = negOne;
    *(char*)(obj + 0x1b) = negOne;
    *(unsigned char*)(obj + 0x1c) = z;
    *(unsigned char*)(obj + 0x1d) = z;
    *(int*)(obj + 0x20) = z;
    *(short*)(obj + 0x24) = negOne;
    *(char*)(obj + 0x26) = negOne;
    *(short*)(obj + 0x1e) = z;
    *(unsigned char*)(obj + 0x27) = z;
}
