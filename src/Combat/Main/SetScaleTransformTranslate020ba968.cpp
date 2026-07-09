#include <globaldefs.h>

struct TransformSrc020ba968 {
    char _00[0x18];
    int f18;
    int f1c;
    char _20[4];
    int f24;
    int f28;
    unsigned short f2c;
    unsigned short f2e;
};

struct AffineTransform020ba968 {
    int m00;
    int m01;
    int _08[2];
    int m10;
    int m11;
    int _18[6];
    int tx;
    int ty;
};

// USA: func_020ba968
ARM void SetScaleTransformTranslate020ba968(struct AffineTransform020ba968* dst, struct TransformSrc020ba968* src) {
    int b;
    int d;
    dst->m00 = src->f18;
    dst->m11 = src->f1c;
    dst->m01 = 0;
    b = ((-src->f2c) << 11) - src->f24 * src->f2c;
    d = src->f28 * src->f2e + ((-src->f2e) << 11);
    dst->tx = (int)(((long long)src->f18 * b) >> 8) + (src->f2c << 15);
    dst->ty = (int)(((long long)src->f1c * d) >> 8) + (src->f2e << 15);
    dst->m10 = 0;
}
