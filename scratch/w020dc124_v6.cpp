#include <globaldefs.h>

extern "C" int func_01ff8b48(unsigned int* stream, int a, int b, int c, int d, int e, int f);
extern unsigned int data_0214e5e4[];

struct Obj020dc124 {
    unsigned char pad1[0x2c];
    int field2c;
    unsigned short field30;
    unsigned short field32;
    unsigned char pad2[0x38 - 0x34];
    int field38;
};

// USA: func_020dc124
ARM int RegisterField020dc124(struct Obj020dc124* obj, int passthrough) {
    if (obj == 0) {
        return -1;
    }
    obj->field32 = obj->field32 | 1;
    int f30 = obj->field30;
    int f2c = obj->field2c;
    int f38 = obj->field38;
    int d = f30 << 3;
    unsigned int c = (unsigned short)f2c << 3;
    int addr = (int)((char*)obj + f38);
    return func_01ff8b48(data_0214e5e4, 0, addr, c, d, passthrough, 0);
}
