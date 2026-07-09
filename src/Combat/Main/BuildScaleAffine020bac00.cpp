#include <globaldefs.h>

struct SpriteTransform020bac00 {
    char _00[0x18];
    int scaleX;             // 0x18
    int scaleY;             // 0x1c
    char _20[0x0c];         // 0x20..0x2b
    unsigned short width;   // 0x2c
    unsigned short height;  // 0x2e
};

struct AffineTransform020bac00 {
    int m00;
    int m01;
    int _08[2];
    int m10;
    int m11;
    int _18[6];
    int tx;
    int ty;
};

// USA: func_020bac00
ARM void BuildScaleAffine020bac00(struct AffineTransform020bac00* dst, struct SpriteTransform020bac00* src) {
    dst->m00 = src->scaleX;
    dst->m11 = src->scaleY;
    dst->m01 = 0;
    dst->tx = (0x1000 - src->scaleX) * src->width << 3;
    dst->ty = (0x1000 - src->scaleY) * src->height << 3;
    dst->m10 = 0;
}
