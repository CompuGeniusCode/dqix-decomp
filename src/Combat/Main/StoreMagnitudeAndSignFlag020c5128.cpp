#include <globaldefs.h>

struct SignedValue020c5128 {
    unsigned short flags;
    unsigned short unk2;
    unsigned short value;
};

// USA: func_020c5128
#pragma optimize_for_size off
ARM void StoreMagnitudeAndSignFlag020c5128(struct SignedValue020c5128* dst, int value) {
    unsigned short flags = dst->flags;
    int state = flags & 0xc0;
    if (value < 0) {
        if (state == 0x80) {
            dst->flags = (flags & ~0xc0) | 0xc0;
        }
        dst->value = -value;
        return;
    }
    if (state == 0xc0) {
        dst->flags = (flags & ~0xc0) | 0x80;
    }
    dst->value = value;
}
