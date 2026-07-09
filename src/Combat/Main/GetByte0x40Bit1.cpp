#include <globaldefs.h>

struct S190 {
    char pad[0x40];
    unsigned char b0 : 1;
    unsigned char b1 : 1;
};

// USA: func_02037190
ARM int GetByte0x40Bit1(struct S190* obj) {
    return obj->b1;
}
