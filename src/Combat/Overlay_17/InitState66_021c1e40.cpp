#include <globaldefs.h>

struct ByteHeader0204693c;
extern void ResetByteHeader(ByteHeader0204693c* p);

struct Struct021c1e40 {
    unsigned char byte0;
    unsigned char pad1[7];
    short h8;
    unsigned char ba0;
    unsigned char bb;
};

// USA: func_ov017_021c1e40
ARM void InitState66_021c1e40(Struct021c1e40* p) {
    ResetByteHeader((ByteHeader0204693c*)p);
    p->byte0 = 0x42;
    p->ba0 = 0;
    p->bb = 0;
    p->h8 = 0x42 - 0x43;
}
