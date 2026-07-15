#include <globaldefs.h>

extern "C" int func_ov000_021819c8(int, int, int*, int);

// USA: func_ov000_02182034
ARM int GetSlotIndex02182034(int unused, int a, int* out, int unused2) {
    return func_ov000_021819c8(a, 3, out, 0);
}
