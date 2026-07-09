#include <globaldefs.h>

struct Block1c02089edc {
    unsigned short v[10];
};

struct Block3002089edc {
    unsigned char v[13];
};

struct Element02089edc {
    signed char b0;
    int w4;
    unsigned char b8;
    short ha;
    int wc;
    unsigned char b10;
    unsigned char b11;
    unsigned char b12;
    int w14;
    int w18;
    struct Block1c02089edc block1c;
    struct Block3002089edc block30;
    unsigned char b3d;
    unsigned char b3e;
    unsigned char b3f;
};

struct ElementArray02089edc {
    struct Element02089edc* base;
    short count;
    short capacity;
};

// USA: func_02089edc
ARM void AppendCappedElement02089edc(struct ElementArray02089edc* arr, struct Element02089edc* src) {
    struct Element02089edc* dst;
    short count;
    if (arr->base == 0) {
        return;
    }
    count = arr->count;
    if (arr->capacity <= count) {
        return;
    }
    dst = &arr->base[count];
    dst->b0 = src->b0;
    dst->w4 = src->w4;
    dst->b8 = src->b8;
    dst->ha = src->ha;
    dst->wc = src->wc;
    dst->b10 = src->b10;
    dst->b11 = src->b11;
    dst->b12 = src->b12;
    dst->w14 = src->w14;
    dst->w18 = src->w18;
    dst->block1c = src->block1c;
    dst->block30 = src->block30;
    dst->b3d = src->b3d;
    dst->b3e = src->b3e;
    dst->b3f = src->b3f;
    arr->count = arr->count + 1;
}
