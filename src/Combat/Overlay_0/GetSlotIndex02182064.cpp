#include <globaldefs.h>

extern "C" int func_ov000_021819c8(int, int, int*, int);

// USA: func_ov000_02182064
ARM int GetSlotIndex02182064(int unused, int a, int* out, int unused2) {
    return func_ov000_021819c8(a, 1, out, 1);
}
