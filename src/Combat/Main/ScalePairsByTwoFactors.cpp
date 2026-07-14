#include <globaldefs.h>

// USA: func_020c1128
ARM void ScalePairsByTwoFactors(int* src, int* dst, int scaleA, int scaleB) {
    dst[0] = (int)(((long long)scaleA * src[0]) >> 12);
    dst[1] = (int)(((long long)scaleA * src[1]) >> 12);
    dst[2] = (int)(((long long)scaleB * src[2]) >> 12);
    dst[3] = (int)(((long long)scaleB * src[3]) >> 12);
}
