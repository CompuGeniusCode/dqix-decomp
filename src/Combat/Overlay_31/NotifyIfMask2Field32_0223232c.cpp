#include <globaldefs.h>

int CheckMaskAgainstField32_0223d354(int mask);
extern "C" void* func_ov031_022368e0(void);
void SetField16IfMinusOne_02222e20(int v);

// USA: func_ov031_0223232c  (semantic: NotifyIfMask2Field32_0223232c)
extern "C" ARM void func_ov031_0223232c() {
    if (CheckMaskAgainstField32_0223d354(2) == 0) {
        return;
    }
    func_ov031_022368e0();
    SetField16IfMinusOne_02222e20(0);
}
