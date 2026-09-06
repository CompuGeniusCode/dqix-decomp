#include <globaldefs.h>

// USA: func_ov031_0220bc18  (semantic: AddCarryPropagate_0220bc18)
extern "C" ARM void func_ov031_0220bc18(unsigned short* dst, unsigned short* src, unsigned int carry, int count) {
    int i = 0;
    if (count > 0) {
        do {
            carry = carry + src[i];
            dst[i] = (unsigned short)carry;
            carry = carry >> 0x10;
            if (carry == 0) break;
            i++;
        } while (i < count);
    }
    if (dst != src) {
        i++;
        if (i < count) {
            do {
                dst[i] = src[i];
                i++;
            } while (i < count);
        }
    }
}
