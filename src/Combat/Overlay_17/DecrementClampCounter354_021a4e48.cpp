#include <globaldefs.h>

// USA: func_ov017_021a4e48
ARM void DecrementClampCounter354_021a4e48(unsigned char* obj) {
    signed char v = *(signed char*)(obj + 0x4300 + 0x54);
    *(signed char*)(obj + 0x4000 + 0x354) = v - 1;
    signed char v2 = *(signed char*)(obj + 0x4300 + 0x54);
    if (v2 < 0) {
        *(signed char*)(obj + 0x4000 + 0x354) = 0;
    }
}
