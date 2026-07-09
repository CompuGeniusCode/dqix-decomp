#include <globaldefs.h>

// USA: func_020c4bd8
ARM int AccumulateSizeFromFlags020c4bd8(int flags) {
    int total = 0;
    if (flags & 0x1) total += 0x20000;
    if (flags & 0x2) total += 0x20000;
    if (flags & 0x4) total += 0x20000;
    if (flags & 0x8) total += 0x20000;
    if (flags & 0x10) total += 0x10000;
    if (flags & 0x20) total += 0x4000;
    if (flags & 0x40) total += 0x4000;
    if (flags & 0x80) total += 0x8000;
    if (flags & 0x100) total += 0x4000;
    return total;
}
