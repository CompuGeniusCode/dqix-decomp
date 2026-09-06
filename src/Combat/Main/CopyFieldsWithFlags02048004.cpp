#include <globaldefs.h>

struct Foo02048004 {
    char unk0[4];
    unsigned short f4;
    unsigned short f6;
    unsigned int w8;
    unsigned int wc;
    unsigned int w10;
    unsigned int w14;
    unsigned int w18;
    char unk1c[0x84 - 0x1c];
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char rest : 6;
};

// USA: func_02048004
ARM void CopyFieldsWithFlags02048004(struct Foo02048004* src, struct Foo02048004* dst) {
    dst->f6 = src->f6;
    dst->w8 = src->w8;
    dst->wc = src->wc;
    dst->w10 = src->w10;
    dst->w14 = src->w14;
    dst->w18 = src->w18;
    dst->f4 = src->f4;
    dst->bit1 = src->bit1;
    dst->bit0 = src->bit0;
}
