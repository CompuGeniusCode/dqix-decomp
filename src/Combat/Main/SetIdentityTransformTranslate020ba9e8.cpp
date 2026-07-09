#include <globaldefs.h>

struct TransformSrc020ba9e8 {
    char _00[0x24];
    int f24;
    int f28;
    unsigned short f2c;
    unsigned short f2e;
};

struct AffineTransform020ba9e8 {
    int m00;
    int m01;
    int _08[2];
    int m10;
    int m11;
    int _18[6];
    int tx;
    int ty;
};

// USA: func_020ba9e8
ARM void SetIdentityTransformTranslate020ba9e8(struct AffineTransform020ba9e8* dst, struct TransformSrc020ba9e8* src) {
    dst->m00 = 0x1000;
    dst->m11 = 0x1000;
    dst->m01 = 0;
    dst->tx = (-src->f24) * (unsigned short)src->f2c << 4;
    dst->ty = src->f28 * (unsigned short)src->f2e << 4;
    dst->m10 = 0;
}
