#include <globaldefs.h>

extern unsigned char data_ov031_02290c70;
ARM void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_0222a288(void);

// USA: func_ov031_0222a328  (semantic: AdvanceCounter70IfReached_0222a328)
extern "C" ARM void func_ov031_0222a328(void) {
    if (++data_ov031_02290c70 < 0x78) return;
    SetField_022274c0_022274c0((int)func_ov031_0222a288);
}
