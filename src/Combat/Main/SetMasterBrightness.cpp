#include <globaldefs.h>

// Writes a signed level into a DS MASTER_BRIGHT register in the form the hardware wants: zero
// disables the effect, positive selects mode 01 and fades toward white, negative mode 10 and fades
// toward black, the magnitude being the five-bit factor. Every caller passes 0x0400006c or
// 0x0400106c; the constant call sites pass levels of 0 and -16, while the main-module path at
// 0x0203b0b8 computes one at runtime from a float, so the range is open. The magnitude is not
// clamped here, so it is on the caller to stay in range. func_020c39c8 is the matching decoder.
extern "C" ARM void SetMasterBrightness(short* out, int value) {
    if (value == 0) {
        *out = 0;
    } else if (value > 0) {
        *out = value | 0x4000;
    } else {
        *out = (-value) | 0x8000;
    }
}
