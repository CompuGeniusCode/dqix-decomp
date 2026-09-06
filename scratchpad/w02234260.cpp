#include <globaldefs.h>

extern "C" void func_ov031_0223429c(void);
extern "C" void func_ov031_022342a0(void);
signed char GetField1b_02237e9c(void);
extern "C" int func_ov031_02236878(int index);
extern "C" void func_ov031_02237e58(void);
extern void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_022342a4(void);

// USA: func_ov031_02234260
ARM void CallStubsThenMaybeSetHandler_02234260(void) {
    func_ov031_0223429c();
    func_ov031_022342a0();
    if (GetField1b_02237e9c() != 0) return;
    func_ov031_02236878(6);
    func_ov031_02237e58();
    func_ov031_02236878(6);
    SetField_022274c0_022274c0((int)func_ov031_022342a4);
}
