#include <globaldefs.h>

struct Src021e6ef8 {
    char pad[8];
    unsigned short h8;
    short ha;
};

extern int data_ov025_021ef988;

// USA: func_ov025_021e6ef8
ARM int CopyFields_021e6ef8_021e6ef8(struct Src021e6ef8* src) {
    short va = src->ha;
    unsigned short v8 = src->h8;
    char* p = *(char**)((char*)&data_ov025_021ef988 + 0xc);
    p += 0x500;
    *(unsigned short*)(p + 0x7e) = v8;
    *(short*)(p + 0x80) = va;
    return 1;
}
