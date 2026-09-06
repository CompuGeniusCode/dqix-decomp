#include <globaldefs.h>

extern unsigned short data_02114e30;

int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
extern "C" int func_0205d97c(void*);

struct Obj021e6e20 { char pad[0xac]; };

// USA: func_ov023_021e6e20
ARM int TestFlagsAndActiveElement2_021e6e20(struct Obj021e6e20* obj) {
    int a = TestFlag0SetAndFlag1Clear(&data_02114e30, 2);
    int b = func_0205d97c((char*)obj + 0xac) == 2;
    return (a | b) != 0;
}
