#include <globaldefs.h>

struct SpriteTransform020baff0 {
    char _00[0x18];
    int scaleX;             // 0x18
    int scaleY;             // 0x1c
    char _20[0x04];         // 0x20..0x23
    int shearX;             // 0x24
    int shearY;             // 0x28
    unsigned short width;   // 0x2c
    unsigned short height;  // 0x2e
};

struct AffineTransform020baff0 {
    int m00;
    int m01;
    int _08[2];
    int m10;
    int m11;
    int _18[6];
    int tx;
    int ty;
};

// USA: func_020baff0
ARM void BuildAffineTransform020baff0(struct AffineTransform020baff0* dst, struct SpriteTransform020baff0* src) {
    int shearTerm;
    dst->m00 = src->scaleX;
    dst->m11 = src->scaleY;
    dst->m01 = 0;
    shearTerm = (int)(((long long)(-src->shearY) * src->scaleY) >> 12);
    dst->tx = src->width * (-(int)(((long long)src->shearX * src->scaleX) >> 12)) << 4;
    dst->ty = (-src->height) * (src->scaleY + shearTerm - 0x1000) << 4;
    dst->m10 = 0;
}
