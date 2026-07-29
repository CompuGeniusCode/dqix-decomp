#include <globaldefs.h>

extern "C" int func_01ff8b48(unsigned int* stream, int a, int b, int c, int d, int e, int f);
extern unsigned int data_0214e5e4[];

struct Obj020dc184 {
    unsigned char pad1[8];
    int field8;
    int fieldC;
    unsigned short field10;
    unsigned char pad2[2];
    int field14;
};

// USA: func_020dc184
ARM int RegisterField020dc184(struct Obj020dc184* obj, int passthrough) {
    if (obj == 0) {
        return -1;
    }
    obj->field10 = obj->field10 | 1;
    int fC = obj->fieldC;
    int d = fC << 3;
    int f8 = obj->field8;
    int f14 = obj->field14;
    unsigned int c = (unsigned short)f8 << 3;
    int addr = (int)((char*)obj + f14);
    return func_01ff8b48(data_0214e5e4, 1, addr, c, d, passthrough, 0);
}
