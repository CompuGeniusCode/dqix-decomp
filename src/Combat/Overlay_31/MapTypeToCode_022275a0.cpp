#include <globaldefs.h>

struct Struct022275a0 { unsigned char byte0; unsigned char pad[7]; unsigned int word8; };
extern Struct022275a0 data_ov031_02250c0c;

// USA: func_ov031_022275a0
ARM int MapTypeToCode_022275a0(void) {
    unsigned char b = data_ov031_02250c0c.byte0;
    if (b == 6) return 0x38;
    if (b == 1) {
        unsigned int hi = data_ov031_02250c0c.word8 >> 4;
        if (!(hi & 2)) return 0x37;
    }
    return (b + 0x31) & 0xff;
}
