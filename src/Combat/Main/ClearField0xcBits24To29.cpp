#include <globaldefs.h>

struct Elem020984b0 {
    unsigned char pad0[0xc];
    unsigned int flags;
    unsigned char pad1[0xd8];
};

// USA: func_020984b0
ARM void ClearField0xcBits24To29(struct Elem020984b0* arr) {
    int i;
    for (i = 0; i < 30; i++) {
        unsigned int* p = (unsigned int*)((char*)arr + i * 0xe8);
        p[3] &= ~0x3f000000;
    }
}
