#include <globaldefs.h>

struct AffineTransform020bac50 {
    int m00;
    int m01;
    int _08[2];
    int m10;
    int m11;
    int _18[6];
    int tx;
    int ty;
};

// USA: func_020bac50
ARM void SetIdentityTransform020bac50(struct AffineTransform020bac50* dst) {
    dst->m00 = 0x1000;
    dst->m01 = 0;
    dst->m10 = 0;
    dst->m11 = 0x1000;
    dst->tx = 0;
    dst->ty = 0;
}
