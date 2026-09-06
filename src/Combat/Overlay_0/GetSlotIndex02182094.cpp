#include <globaldefs.h>

extern "C" int func_ov000_021819c8(int, int, int*, int);

// USA: func_ov000_02182094
ARM int GetSlotIndex02182094(int unused, int a, int* out, int unused2) {
    return func_ov000_021819c8(a, 3, out, 1);
}
