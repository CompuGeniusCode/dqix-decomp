#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
extern int TailCall_02222ddc(void);
extern "C" void func_ov031_0223c078(int, int, int, int);
extern void SetField_022274c0_022274c0(int);
extern void RunChecksAndSetHandler_022313a0(void);

extern unsigned char data_ov031_02290cac;

// USA: func_ov031_0223132c  (semantic: ConditionalSetupAndRegisterHandler_0223132c)
extern "C" ARM void func_ov031_0223132c(void) {
    if (func_ov031_0223c054(1) != 0) {
        return;
    }
    if (data_ov031_02290cac == 0) {
        TailCall_02222ddc();
    }
    if (data_ov031_02290cac == 0) {
        func_ov031_0223c078(3, 1, 1, 8);
    }
    func_ov031_0223c078(3, 0, 0x15, 8);
    SetField_022274c0_022274c0((int)RunChecksAndSetHandler_022313a0);
}
