#include <globaldefs.h>

void StartHwDivide(unsigned int numerHi, unsigned int denomLo);
int GetDivResultFixed20(void);

struct SpriteTransform020ba778 {
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

struct AffineTransform020ba778 {
    int m00;
    int m01;
    int _08[2];
    int m10;
    int m11;
    int _18[6];
    int tx;
    int ty;
};

// USA: func_020ba778  (semantic: BuildRotateScaleTranslateAffine020ba778)
extern "C" ARM void func_020ba778(struct AffineTransform020ba778* dst, struct SpriteTransform020ba778* src) {
    unsigned int c12 = (unsigned int)src->f2c << 12;
    unsigned int e12 = (unsigned int)src->f2e << 12;
    StartHwDivide(e12, c12);
    int a = (int)(((long long)src->f18 * src->f22) >> 12);
    int b = (int)(((long long)src->f18 * src->f20) >> 12);
    int d = (int)(((long long)src->f1c * src->f22) >> 12);
    int c = (int)(((long long)src->f1c * src->f20) >> 12);
    dst->m00 = a;
    dst->m11 = d;
    int div1 = GetDivResultFixed20();
    dst->m01 = (c * div1) >> 12;
    StartHwDivide(c12, e12);
    unsigned short fc = src->f2c;
    unsigned short fe = src->f2e;
    int negC = -(int)fc;
    int prodP = src->f28 * fe;
    int negE = -(int)fe;
    int P = prodP + (negE << 11);
    long long dP = (long long)d * P;
    long long bP = (long long)b * P;
    int fc24 = src->f24 * fc;
    int Q = (negC << 11) - fc24;
    long long aQ = (long long)a * Q;
    long long cQ = (long long)c * Q;
    long long ty64 = cQ + dP;
    long long tx64 = aQ - bP;
    dst->tx = (int)(tx64 >> 8) + (fc << 15);
    dst->ty = (src->f2e << 15) + (int)(ty64 >> 8);
    int div2 = GetDivResultFixed20();
    dst->m10 = (-b * div2) >> 12;
}
