#include <globaldefs.h>

// USA: func_020349e8
ARM void ScaleU5ValueToU16(unsigned short* out, float val) {
    *out = (unsigned int)(65535.0f * (val / 31.0f));
}
