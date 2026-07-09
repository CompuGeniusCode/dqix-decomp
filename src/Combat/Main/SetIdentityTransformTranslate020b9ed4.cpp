#include <globaldefs.h>

struct TransformSrc020b9ed4 {
    char _00[0x24];
    int f24;
    int f28;
    unsigned short f2c;
    unsigned short f2e;
};

struct AffineTransform020b9ed4 {
    int m00;
    int m01;
    int _08[2];
    int m10;
    int m11;
    int _18[6];
    int tx;
    int ty;
};

// USA: func_020b9ed4
ARM void SetIdentityTransformTranslate020b9ed4(struct AffineTransform020b9ed4* dst, struct TransformSrc020b9ed4* src) {
    dst->m00 = 0x1000;
    dst->m11 = 0x1000;
    dst->m01 = 0;
    dst->tx = -(src->f24 * src->f2c) << 4;
    dst->ty = (src->f28 * src->f2e) << 4;
    dst->m10 = 0;
}
