#include <globaldefs.h>

struct Bytes6_0202ba08 { char v[6]; };
struct Bytes32_0202ba08 { char v[0x20]; };
struct Words32_0202ba08 { unsigned int v[0x20]; };

struct Record0202ba08 {
    unsigned short h0;
    unsigned short h2;
    struct Bytes6_0202ba08 b4;
    unsigned short ha;
    struct Bytes32_0202ba08 bc;
    unsigned short h2c;
    unsigned short h2e;
    unsigned short h30;
    unsigned short h32;
    unsigned short h34;
    unsigned short h36;
    unsigned short h38;
    unsigned short h3a;
    unsigned short h3c;
    unsigned short h3e;
    struct Words32_0202ba08 w40;
};

// USA: func_0202ba08
ARM struct Record0202ba08* CopyRecord0202ba08(struct Record0202ba08* dst, struct Record0202ba08* src) {
    dst->h0 = src->h0;
    dst->h2 = src->h2;
    dst->b4 = src->b4;
    dst->ha = src->ha;
    dst->bc = src->bc;
    dst->h2c = src->h2c;
    dst->h2e = src->h2e;
    dst->h30 = src->h30;
    dst->h32 = src->h32;
    dst->h34 = src->h34;
    dst->h36 = src->h36;
    dst->h38 = src->h38;
    dst->h3a = src->h3a;
    dst->h3c = src->h3c;
    dst->h3e = src->h3e;
    dst->w40 = src->w40;
    return dst;
}
