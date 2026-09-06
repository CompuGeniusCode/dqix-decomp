#include <globaldefs.h>

struct SubObj02162c90 { char pad[0x4f4]; int val; };

// USA: func_ov000_02162c90
ARM void SetBoundedArrayField0x4f4(char* base, int index, int value) {
    int valid = (index >= 0 && index <= 3);
    if (valid) {
        ((struct SubObj02162c90*)(base + index * 4 + 0x5000))->val = value;
    }
}
