#include <globaldefs.h>

extern "C" int func_ov023_021f6558(void* a, int b);
extern "C" void func_ov004_021660f4(void);
extern "C" void func_ov004_02165f2c(void);
extern "C" void func_ov004_02165ef4(void* a1);
extern "C" void func_ov011_021848a0(void* obj, int val);

struct BitField02166b40 {
    char pad[0x48];
    short count0;
    short count1;
    char pad2[4];
    unsigned char loFlags : 6;
    unsigned char bit6 : 1;
    unsigned char bit7 : 1;
};
extern struct BitField02166b40* data_ov004_0217101c;

// USA: func_ov004_02166b40  (semantic: UpdateFlags50AndDispatch_02166b40)
#pragma optimize_for_size off
extern "C" ARM int func_ov004_02166b40(void* a1) {
    struct BitField02166b40* obj = data_ov004_0217101c;
    int r = func_ov023_021f6558(a1, 0x5a);
    short val;
    if (r != 0xb4 && r == 0xb5) {
        obj->bit6 = 1;
        obj->bit7 = 1;
        val = obj->count1;
    } else {
        obj->bit6 = 0;
        obj->bit7 = 1;
        val = obj->count0;
    }

    if (val != 0) {
        func_ov004_021660f4();
        func_ov004_02165f2c();
        func_ov004_02165ef4(a1);
        func_ov011_021848a0(a1, 0x12d);
    } else {
        func_ov011_021848a0(a1, 0x66);
    }
    return 0;
}
