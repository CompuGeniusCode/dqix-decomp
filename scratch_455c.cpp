#include <globaldefs.h>

// USA: func_0204455c
ARM void func_0204455c(void *obj, short *out1, short *out2) {
    if (obj == 0) return;
    int a = *(short*)((char*)obj + 0xa8);
    int b = *(short*)((char*)obj + 0xac);
    int c = *(short*)((char*)obj + 0xaa);
    int ea = (a << 19) >> 17;
    *out1 = (short)(ea + ((b << 19) >> 16));
    *out2 = (short)(((c << 19) >> 16) - 10);
}
