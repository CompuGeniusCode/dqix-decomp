#include <globaldefs.h>

void StartHwDivide(unsigned int numerHi, unsigned int denomLo);
int GetDivResultFixed20(void);

struct SpriteTransform020b9f1c {
    char _00[0x18];
    int f18;
    int f1c;
    short f20;
    short f22;
    char _24[0x8];
    unsigned short f2c;
    unsigned short f2e;
};

struct AffineTransform020b9f1c {
    int m00;
    int m01;
    int _08[2];
    int m10;
    int m11;
    int _18[6];
    int tx;
    int ty;
};

// USA: func_020b9f1c
ARM void BuildScaleRotateAffine020b9f1c(struct AffineTransform020b9f1c* dst, struct SpriteTransform020b9f1c* src) {
    unsigned int c12 = (unsigned int)src->f2c << 12;
    unsigned int e12 = (unsigned int)src->f2e << 12;
    StartHwDivide(e12, c12);
    int b = (int)(((long long)src->f18 * src->f20) >> 12);
    int a = (int)(((long long)src->f18 * src->f22) >> 12);
    int c = (int)(((long long)src->f1c * src->f20) >> 12);
    int d = (int)(((long long)src->f1c * src->f22) >> 12);
    dst->m00 = a;
    dst->m11 = d;
    int div1 = GetDivResultFixed20();
    dst->m01 = ((-c) * div1) >> 12;
    StartHwDivide(c12, e12);
    dst->tx = (src->f2c * (src->f18 - (b + a))) << 3;
    dst->ty = (src->f2e * ((c - d) - src->f1c + 0x2000)) << 3;
    int div2 = GetDivResultFixed20();
    dst->m10 = (b * div2) >> 12;
}
