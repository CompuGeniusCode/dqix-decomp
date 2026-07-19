#include <globaldefs.h>

extern "C" void func_ov031_02228be0(void);
extern "C" void func_ov031_02223998(int);
extern "C" void func_ov031_0222336c(int, int, int);
extern "C" void func_ov031_02228c60(void);
ARM void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_02228e64(void);

// USA: func_ov031_02228bac  (semantic: ConfigureThenDispatch_02228bac)
extern "C" ARM void func_ov031_02228bac(void) {
    func_ov031_02228be0();
    func_ov031_02223998(0x11);
    func_ov031_0222336c(0x3a, 0x3a - 0x3b, 0);
    func_ov031_02228c60();
    SetField_022274c0_022274c0((int)func_ov031_02228e64);
}
