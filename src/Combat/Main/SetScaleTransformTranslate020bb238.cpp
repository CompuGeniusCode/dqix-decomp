#include <globaldefs.h>

struct TransformSrc020bb238 {
    char _00[0x18];
    int f18;
    int f1c;
    char _20[0xe];
    unsigned short f2e;
};

struct AffineTransform020bb238 {
    int m00;
    int m01;
    int _08[2];
    int m10;
    int m11;
    int _18[6];
    int tx;
    int ty;
};

// USA: func_020bb238
ARM void SetScaleTransformTranslate020bb238(struct AffineTransform020bb238* dst, struct TransformSrc020bb238* src) {
    dst->m00 = src->f18;
    dst->m11 = src->f1c;
    dst->m01 = 0;
    dst->tx = 0;
    dst->ty = (-(unsigned short)src->f2e) * (src->f1c - 0x1000) << 4;
    dst->m10 = 0;
}
