#include <globaldefs.h>

struct Payload18_02030310 {
    char data[0x18];
};

struct CopyableRecord02030310 {
    struct Payload18_02030310 a;
    struct Payload18_02030310 b;
    short c;
    signed char d;
    unsigned char e;
    int f;
    int g;
    int h;
    unsigned short i;
    unsigned short j;
};

// USA: func_02030310
ARM void CopyRecord02030310(struct CopyableRecord02030310* dst, struct CopyableRecord02030310* src) {
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->d = src->d;
    dst->e = src->e;
    dst->f = src->f;
    dst->g = src->g;
    dst->h = src->h;
    dst->i = src->i;
    dst->j = src->j;
}
