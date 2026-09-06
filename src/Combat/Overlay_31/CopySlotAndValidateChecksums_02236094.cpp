#include <globaldefs.h>

extern "C" int func_02001aec(unsigned char* a, unsigned char* b, int len);
void WriteMaskBytes_0221b19c(int val, unsigned char* out);

extern unsigned char* data_ov031_02290cfc;
extern unsigned char data_ov031_02249248;

// USA: func_ov031_02236094  (semantic: CopySlotAndValidateChecksums_02236094)
extern "C" ARM void func_ov031_02236094(unsigned char param) {
    unsigned char* g = data_ov031_02290cfc;
    unsigned char* slot = g + (param << 8);
    int n = 0x78;
    unsigned char* dst = g + 0x400;
    unsigned char* src = slot;

    do {
        unsigned char b0 = src[0];
        unsigned char b1 = src[1];
        src += 2;
        n--;
        dst[0] = b0;
        dst[1] = b1;
        dst += 2;
    } while (n != 0);

    g[0x4f4] = param;

    if (func_02001aec(slot + 0xc0, &data_ov031_02249248, 4) != 0) {
        data_ov031_02290cfc[0x4f5] = 0;
    } else {
        data_ov031_02290cfc[0x4f5] = 1;
    }

    if (func_02001aec(slot + 0xc8, &data_ov031_02249248, 4) != 0 ||
        func_02001aec(slot + 0xcc, &data_ov031_02249248, 4) != 0) {
        data_ov031_02290cfc[0x4f6] = 0;
    } else {
        data_ov031_02290cfc[0x4f6] = 1;
    }

    WriteMaskBytes_0221b19c(slot[0xd0], data_ov031_02290cfc + 0x4f0);
}
