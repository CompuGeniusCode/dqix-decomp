#include <globaldefs.h>

struct SpriteTransform020bb074 {
    char _00[0x24];
    int shearX;             // 0x24
    int shearY;             // 0x28
    unsigned short width;   // 0x2c
    unsigned short height;  // 0x2e
};

struct AffineTransform020bb074 {
    int m00;
    int m01;
    int _08[2];
    int m10;
    int m11;
    int _18[6];
    int tx;
    int ty;
};

// USA: func_020bb074
ARM void BuildTranslateAffine020bb074(struct AffineTransform020bb074* dst, struct SpriteTransform020bb074* src) {
    int negShearY;
    dst->m00 = 0x1000;
    dst->m11 = 0x1000;
    dst->m01 = 0;
    negShearY = -src->shearY;
    dst->tx = src->width * (-src->shearX) << 4;
    dst->ty = (-src->height) * negShearY << 4;
    dst->m10 = 0;
}
