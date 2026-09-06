#include <globaldefs.h>

struct ByteHeader0204693c;
extern void ResetByteHeader(struct ByteHeader0204693c* p);

// USA: func_ov004_0216fa08  (semantic: ResetFieldsAndHeader_0216fa08)
extern "C" ARM void func_ov004_0216fa08(void* a) {
    ResetByteHeader((struct ByteHeader0204693c*)a);
    unsigned char* base = (unsigned char*)a;
    base[0] = 0x36;
    *(short*)(base + 8) = 0;
    base[0xa] = 0;
    *(short*)(base + 0xc) = -1;
    base[0xe] = 0;
    base[0xf] = 0;
}
