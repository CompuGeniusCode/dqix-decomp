#include <globaldefs.h>

int GetData02104304Field4();
extern "C" void func_020301c8(int, int);

// USA: func_ov023_021db2e4
ARM void ResetIfNonNeg_021db2e4(volatile int* p) {
    if (!p) return;
    if (*p < 0) return;
    func_020301c8(GetData02104304Field4(), *p);
    *p = -1;
}
