#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
extern int IsPtr02290c44Null_02227840(void);
extern "C" void func_ov031_02223b1c(void);
extern "C" void func_ov031_02222bdc(void);
extern void* TailCallElemAtIndex30_0223c7c4(int);
extern "C" void func_ov031_0223cbbc(int, int);
extern void SetField1014_022274d0(int, int);
extern void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_0222a35c(void);
ARM void ResetAndDispatch_0222a174(void);
ARM void Setup1fAndAdvance_022299ec(void);
extern unsigned char data_ov031_02290c68;

// USA: func_ov031_022298d0  (semantic: RunChecksAndDispatchMode_022298d0)  (semantic: RunChecksAndDispatchMode_022298d0)
extern "C" ARM void func_ov031_022298d0(void) {
    if (func_ov031_0223c054(0) != 0) return;
    if (IsPtr02290c44Null_02227840() == 0) return;
    func_ov031_02223b1c();
    func_ov031_02222bdc();
    TailCallElemAtIndex30_0223c7c4(0);
    func_ov031_0223cbbc(0, 0x15);
    SetField1014_022274d0(0, 1);

    if (data_ov031_02290c68 == 0) {
        SetField_022274c0_022274c0((int)func_ov031_0222a35c);
    } else if (data_ov031_02290c68 == 2) {
        SetField_022274c0_022274c0((int)ResetAndDispatch_0222a174);
    } else {
        SetField_022274c0_022274c0((int)Setup1fAndAdvance_022299ec);
    }
}
