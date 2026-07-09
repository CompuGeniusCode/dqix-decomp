#include <globaldefs.h>

struct TransformSrc020ba0b4 {
    char _00[0x18];
    int f18;
    int f1c;
    char _20[0xe];
    unsigned short f2e;
};

struct AffineTransform020ba0b4 {
    int m00;
    int m01;
    int _08[2];
    int m10;
    int m11;
    int _18[6];
    int tx;
    int ty;
};

// USA: func_020ba0b4
ARM void SetScaleTransformTranslate020ba0b4(struct AffineTransform020ba0b4* dst, struct TransformSrc020ba0b4* src) {
    dst->m00 = src->f18;
    dst->m11 = src->f1c;
    dst->m01 = 0;
    dst->tx = 0;
    dst->ty = (src->f2e * (src->f1c * -2 + 0x2000)) << 3;
    dst->m10 = 0;
}
