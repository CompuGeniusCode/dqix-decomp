#include <globaldefs.h>

// USA: func_ov017_021a85e8
#pragma optimize_for_size off
ARM int DecrementField38Clamped_021a85e8(unsigned char* obj, int amount) {
    short* f = (short*)(obj + 0x38);
    if (*f > amount) {
        *f -= amount;
    } else {
        *f = 0;
        return 0;
    }
    return 1;
}
