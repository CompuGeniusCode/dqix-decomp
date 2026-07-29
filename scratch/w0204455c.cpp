#include <globaldefs.h>

// USA: func_0204455c
ARM void SetScaledPosFromObj0204455c(volatile void* obj, short* out1, short* out2) {
    if (!obj) return;
    int a = *(volatile short*)((char*)obj + 0xa8);
    int c = *(volatile short*)((char*)obj + 0xac);
    int b = *(volatile short*)((char*)obj + 0xaa);
    int fa = (a << 19) >> 17;
    int gc = (c << 19) >> 16;
    int gb = (b << 19) >> 16;
    *out1 = gc + fa;
    *out2 = gb - 10;
}
