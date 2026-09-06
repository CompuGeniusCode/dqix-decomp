#include <globaldefs.h>

extern "C" int func_ov000_021819c8(int, int, int*, int);

// USA: func_ov000_0218204c
ARM int GetSlotIndex0218204c(int unused, int a, int* out, int unused2) {
    return func_ov000_021819c8(a, 0, out, 1);
}
