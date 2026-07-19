#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
ARM int IsPtr02290c44Null_02227840(void);
extern void SetField_022274c0_022274c0(int);
ARM void CallStubPair_0222a274(void);

// USA: func_ov031_0222a244  (semantic: SetHandlerIfPtrSet_0222a244)
extern "C" ARM void func_ov031_0222a244(void) {
    if (func_ov031_0223c054(0) != 0) return;
    if (IsPtr02290c44Null_02227840() == 0) return;
    SetField_022274c0_022274c0((int)CallStubPair_0222a274);
}
