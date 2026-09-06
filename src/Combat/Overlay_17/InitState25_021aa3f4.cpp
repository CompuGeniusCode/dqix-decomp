#include <globaldefs.h>

struct ByteHeader0204693c;
extern void ResetByteHeader(ByteHeader0204693c* p);

struct Struct021aa3f4 {
    unsigned char byte0;
    unsigned char pad1[7];
    unsigned short h8;
    unsigned short ha;
    unsigned short hc;
};

// USA: func_ov017_021aa3f4
ARM void InitState25_021aa3f4(Struct021aa3f4* p) {
    ResetByteHeader((ByteHeader0204693c*)p);
    p->byte0 = 0x19;
    p->h8 = 0;
    p->ha = 0;
    p->hc = 0;
}
