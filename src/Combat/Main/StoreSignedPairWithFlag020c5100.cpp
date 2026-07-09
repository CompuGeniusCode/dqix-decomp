#include <globaldefs.h>
#pragma optimize_for_size off

// USA: func_020c5100
ARM void StoreSignedPairWithFlag020c5100(unsigned short* dst, int flag, int value) {
    if (value < 0) {
        dst[0] = flag | 0xc0;
        dst[2] = -value;
        return;
    }
    dst[0] = flag | 0x80;
    dst[2] = value;
}
