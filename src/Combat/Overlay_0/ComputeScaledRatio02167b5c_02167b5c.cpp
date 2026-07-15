#include <globaldefs.h>

extern "C" int _s32_div_f(int a, int b);

// USA: func_ov000_02167b5c
ARM int ComputeScaledRatio02167b5c(int a, int b) {
    int bm1 = b - 1;
    int result = 0xb33;
    int ip = bm1 * 0x199 + 0x4000;
    int r3 = bm1 * 0xb33 + a;
    if (r3 >= ip) {
        if (ip < a) {
            result = 0x199;
        } else if ((unsigned int)b > 1) {
            result = _s32_div_f(ip - a, bm1);
        }
    }
    return result;
}
