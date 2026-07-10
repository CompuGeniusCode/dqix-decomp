#include <globaldefs.h>

struct S02036000 {
    unsigned char pad[0x44];
    unsigned int f44;
    unsigned int f48;
    unsigned int f4c;
};

// USA: func_02036000
ARM void WriteVec3ToReg02036000(struct S02036000* obj) {
    unsigned int z = obj->f4c;
    unsigned int y = obj->f48;
    unsigned int x = obj->f44;
    volatile unsigned int* reg = (volatile unsigned int*)0x4000470;
    *reg = x;
    *reg = y;
    *reg = z;
}
