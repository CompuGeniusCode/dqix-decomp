#include <globaldefs.h>

void StartHwDivide(unsigned int numerHi, unsigned int denomLo);
int GetDivResultFixed20(void);

struct SpriteTransform020bb194 {
    char _00[0x20];
    short f20;
    short f22;
    char _24[0x08];
    unsigned short f2c;
    unsigned short f2e;
};

struct AffineTransform020bb194 {
    int m00;
    int m01;
    int _08[2];
    int m10;
    int m11;
    int _18[6];
    int tx;
    int ty;
};

// USA: func_020bb194
ARM void BuildRotateScaleAffine020bb194(struct AffineTransform020bb194* dst, struct SpriteTransform020bb194* src) {
    unsigned int c12 = (unsigned int)src->f2c << 12;
    unsigned int e12 = (unsigned int)src->f2e << 12;
    StartHwDivide(e12, c12);
    dst->m00 = src->f22;
    dst->m11 = src->f22;
    int div1 = GetDivResultFixed20();
    dst->m01 = (src->f20 * div1) >> 12;
    StartHwDivide(c12, e12);
    dst->tx = (src->f2c * src->f20) << 4;
    dst->ty = (-(int)src->f2e) * (src->f22 - 0x1000) << 4;
    int div2 = GetDivResultFixed20();
    dst->m10 = (-src->f20) * div2 >> 12;
}
