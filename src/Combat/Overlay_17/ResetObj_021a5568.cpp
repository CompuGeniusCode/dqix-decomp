#include <globaldefs.h>

struct ByteHeader0204693c;
extern void ResetByteHeader(ByteHeader0204693c* p);

struct Obj021a5568 {
    unsigned char byte0;
    unsigned char pad0[7];
    int f8;
    unsigned char pad1[0x14];
    unsigned char f20;
    unsigned char f21;
    short f22;
};

extern int data_ov017_021d83ac;

// USA: func_ov017_021a5568  (semantic: ResetObj_021a5568)
extern "C" ARM void func_ov017_021a5568(Obj021a5568* p) {
    ResetByteHeader((ByteHeader0204693c*)p);
    p->byte0 = 0xc;
    p->f8 = 0;
    data_ov017_021d83ac = 0;
    p->f20 = 0;
    p->f21 = 0;
    p->f22 = -1;
}
