#include <globaldefs.h>

extern "C" void func_020ca3b8(void* src, void* dst, unsigned int len);

struct BitField3_020c99c8 { unsigned short v : 3; };
struct BitField4_020c99c8 { unsigned char v : 4; };

// USA: func_020c99c8  (semantic: InitStructFromFixedTable020c99c8)
extern "C" ARM void func_020c99c8(void* dst) {
    char* d = (char*)dst;
    unsigned char* s = (unsigned char*)0x27ffc80;
    d[0] = ((struct BitField3_020c99c8*)(s + 0x64))->v;
    d[1] = ((struct BitField4_020c99c8*)(s + 2))->v;
    d[2] = s[3];
    d[3] = s[4];
    *(unsigned short*)(d + 0x1a) = (unsigned char)s[0x1a];
    *(unsigned short*)(d + 0x52) = (unsigned char)s[0x50];
    func_020ca3b8(s + 6, d + 4, 0x14);
    func_020ca3b8(s + 0x1c, d + 0x1c, 0x34);
    *(unsigned short*)(d + 0x18) = 0;
    *(unsigned short*)(d + 0x50) = 0;
}
