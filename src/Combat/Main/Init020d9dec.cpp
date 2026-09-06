#include <globaldefs.h>

struct ByteHeader0204693c;
extern void ResetByteHeader(ByteHeader0204693c* p);

struct Struct020d9dec {
    unsigned char byte0;
    unsigned char pad1;
    unsigned char byte2;
    unsigned char pad3[5];
    unsigned short half8;
    unsigned char byteA;
    unsigned char padB;
    int field_c[1];
};

// USA: func_020d9dec
ARM void Init020d9dec(Struct020d9dec* p, int flag) {
    int i;
    if (flag == 0 && p->byte2 != 0) return;
    ResetByteHeader((ByteHeader0204693c*)p);
    p->byte0 = 0x49;
    p->half8 = 0;
    p->byteA = 0;
    for (i = 0; i < 1; i++) {
        p->field_c[i] = -1;
    }
}
