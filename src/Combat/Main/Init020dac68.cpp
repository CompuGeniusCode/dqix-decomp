#include <globaldefs.h>

struct ByteHeader0204693c;
extern void ResetByteHeader(ByteHeader0204693c* p);

struct Struct020dac68 {
    unsigned char byte0;
    unsigned char pad1[11];
    int field_c;
    int field_10;
    unsigned char pad14[0x14];
    unsigned char byte28;
};

// USA: func_020dac68
ARM void Init020dac68(Struct020dac68* p) {
    ResetByteHeader((ByteHeader0204693c*)p);
    p->byte0 = 0x4b;
    p->field_c = 0;
    p->field_10 = 0;
    p->byte28 = 0xff;
}
