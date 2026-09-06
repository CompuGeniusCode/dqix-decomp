#include <globaldefs.h>

struct Rec021ed35c {
    char pad0[0x150];
    unsigned char e150;
    unsigned char e151;
    unsigned char pad2[0x152 - 0x152];
};

// USA: func_ov025_021ed35c
ARM void ResetFields_021ed35c(char* base) {
    *(unsigned short*)(base + 0x100 + 0x5e) = 0;
    base[0x150] = 0;
    *(unsigned short*)(base + 0x100 + 0x52) = 0;
    *(unsigned short*)(base + 0x100 + 0x54) = 0;
    base[0x151] = 0;
    *(unsigned short*)(base + 0x100 + 0x5c) = 0;
}
