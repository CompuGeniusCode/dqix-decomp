#include <globaldefs.h>

struct TransformSrc020b9e58 {
    char _00[0x18];
    int f18;
    int f1c;
    char _20[4];
    int f24;
    int f28;
    unsigned short f2c;
    unsigned short f2e;
};

struct AffineTransform020b9e58 {
    int m00;
    int m01;
    int _08[2];
    int m10;
    int m11;
    int _18[6];
    int tx;
    int ty;
};

// USA: func_020b9e58
ARM void SetScaleTransformTranslate020b9e58(struct AffineTransform020b9e58* dst, struct TransformSrc020b9e58* src) {
    int u;
    int v;
    dst->m00 = src->f18;
    dst->m11 = src->f1c;
    dst->m01 = 0;
    dst->tx = src->f2c * -(int)(((long long)src->f18 * src->f24) >> 8);
    u = (int)(((long long)src->f1c * src->f28) >> 8);
    v = src->f1c * -2 + 0x2000;
    dst->ty = ((src->f2e * v) << 3) + src->f2e * u;
    dst->m10 = 0;
}
