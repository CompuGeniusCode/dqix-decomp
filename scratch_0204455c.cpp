#include <globaldefs.h>

// USA: func_0204455c
ARM void ComputeScaledFields_0204455c(void* obj, short* out1, short* out2) {
    if (obj == 0) return;
    int sb = *(short*)((char*)obj + 0xaa) << 19;
    int sc = *(short*)((char*)obj + 0xac) << 19;
    int sa = *(short*)((char*)obj + 0xa8) << 19;
    int ea = sa >> 17;
    *out1 = (short)(ea + (sc >> 16));
    *out2 = (short)((sb >> 16) - 10);
}
