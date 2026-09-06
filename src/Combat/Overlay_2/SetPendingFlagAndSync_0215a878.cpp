#include <globaldefs.h>

extern "C" char* func_ov017_0218b5b0(void);

// USA: func_ov002_0215a878
ARM void SetPendingFlagAndSync_0215a878(char* p) {
    short v1 = *(short*)(p + 0x1b00 + 0xe0);
    *(unsigned int*)(p + 0x2000 + 0x540) = v1;
    short v2 = *(short*)(p + 0x1b00 + 0xfe);
    *(unsigned int*)(p + 0x2000 + 0x544) = v2;
    *(unsigned char*)(p + 0x2000 + 0x53c) = 1;
    char* other = func_ov017_0218b5b0();
    char* obj2 = *(char**)(other + 0x3000 + 0x71c);
    *(unsigned char*)(obj2 + 0x24) = *(unsigned char*)(p + 0x2000 + 0x53c);
    *(unsigned int*)(obj2 + 0x28) = *(unsigned int*)(p + 0x2000 + 0x540);
    *(unsigned int*)(obj2 + 0x2c) = *(unsigned int*)(p + 0x2000 + 0x544);
}
