#include <globaldefs.h>

struct S02036060 {
    unsigned char pad[0x5c];
    short f5c;
    short f5e;
    short f60;
};

// USA: func_02036060
ARM void WriteVec3ShortToReg02036060(struct S02036060* obj) {
    int z = obj->f60;
    int y = obj->f5e;
    int x = obj->f5c;
    volatile unsigned int* reg = (volatile unsigned int*)0x400046c;
    *reg = x;
    *reg = y;
    *reg = z;
}
