#include <globaldefs.h>

struct BitFlags020d805c {
    char pad[0x150];
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
};

// USA: func_020d805c
ARM int GetByte0x150Bit6(struct BitFlags020d805c* obj) {
    return obj->b6;
}
