#include <globaldefs.h>

void StartHwDivide(unsigned int numerHi, unsigned int denomLo);
int GetDivResultFixed20(void);

struct SpriteTransform020b9c80 {
    char _00[0x18];
    int f18;
    int f1c;
    short f20;
    short f22;
    int f24;
    int f28;
    unsigned short f2c;
    unsigned short f2e;
};

struct AffineTransform020b9c80 {
    int m00;
    int m01;
    int _08[2];
    int m10;
    int m11;
    int _18[6];
    int tx;
    int ty;
};

// USA: func_020b9c80  (semantic: BuildScaleRotateTranslateAffine020b9c80)
extern "C" ARM void func_020b9c80(struct AffineTransform020b9c80* dst, struct SpriteTransform020b9c80* src) {
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
    int tx = (src->f2c * (src->f18 - (b + a))) << 3;
    tx -= src->f2c * (int)(((long long)src->f18 * src->f24) >> 8);
    dst->tx = tx;
    int ty = (src->f2e * ((c - d) - src->f1c + 0x2000)) << 3;
    ty += src->f2e * (int)(((long long)src->f1c * src->f28) >> 8);
    dst->ty = ty;
    int div2 = GetDivResultFixed20();
    dst->m10 = (b * div2) >> 12;
}
