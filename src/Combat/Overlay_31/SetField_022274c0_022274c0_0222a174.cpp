#include <globaldefs.h>

extern unsigned char data_ov031_02290c70;
extern "C" void func_ov031_0222a1a4(void);
extern "C" void func_ov031_022235a0(int);
ARM void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_0222a210(void);

// USA: func_ov031_0222a174
ARM void ResetAndDispatch_0222a174(void) {
    data_ov031_02290c70 = 0;
    func_ov031_0222a1a4();
    func_ov031_022235a0(0x21);
    SetField_022274c0_022274c0((int)func_ov031_0222a210);
}
