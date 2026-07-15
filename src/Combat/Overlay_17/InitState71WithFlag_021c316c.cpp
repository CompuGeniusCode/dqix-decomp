#include <globaldefs.h>

struct ByteHeader0204693c;
extern void ResetByteHeader(ByteHeader0204693c* p);

struct Struct021c316c {
    unsigned char byte0;
    unsigned char pad1[7];
    unsigned char b8;
    unsigned char b9;
};

// USA: func_ov017_021c316c
ARM void InitState71WithFlag_021c316c(Struct021c316c* p, int flag) {
    ResetByteHeader((ByteHeader0204693c*)p);
    p->byte0 = 0x47;
    p->b8 = 0;
    p->b9 = (unsigned char)flag;
}
