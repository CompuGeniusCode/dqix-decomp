#include <globaldefs.h>

struct Obj021761c8 { char pad[0xd1c]; int arr[8]; };

// USA: func_ov000_021761c8
ARM int GetClampedArrayField0xd1c(char* base, int index) {
    if (index < 0 || index >= 8) index = 0;
    return ((struct Obj021761c8*)(base + 0x1000))->arr[index];
}
