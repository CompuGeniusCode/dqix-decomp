#include <globaldefs.h>

extern "C" void func_0207de48(void* p, int a, int b);
extern int data_ov023_021fd6ac[];
extern int data_ov023_021fd6fc[];

// USA: func_ov023_021e4fd8
ARM void InitBlockArray_021e4fd8(void* obj) {
    char* base;
    int i;
    base = (char*)obj + 0x394;
    i = 0;
    base = base + 0x400;
    for (; i < 10; i++) {
        func_0207de48(base + i * 0x70, data_ov023_021fd6ac[i], data_ov023_021fd6fc[i]);
    }
}
