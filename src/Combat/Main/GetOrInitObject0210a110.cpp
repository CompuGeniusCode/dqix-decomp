#include <globaldefs.h>

extern "C" void func_020c19d4(void* a, void* b);
extern int data_0210a010[];
extern int data_0210a05c;
extern int data_0210a110;

// USA: func_020b3950
ARM void* GetOrInitObject0210a110(void) {
    if ((data_0210a010[0x3f] & 0x8) == 0) {
        func_020c19d4(&data_0210a05c, &data_0210a110);
        data_0210a010[0x3f] |= 0x8;
    }
    return &data_0210a110;
}
