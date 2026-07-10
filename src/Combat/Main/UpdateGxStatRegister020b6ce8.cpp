#include <globaldefs.h>

extern "C" void func_020c51dc(void);
extern "C" void func_020b36c0(void);

// USA: func_020b6ce8
ARM void UpdateGxStatRegister020b6ce8(void) {
    func_020c51dc();
    func_020b36c0();
    *(volatile unsigned int*)0x4000600 =
        (*(volatile unsigned int*)0x4000600 & ~0xc0000000) | 0x80000000;
}
