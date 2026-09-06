#include <globaldefs.h>

struct FiveWordsAndByte_021dcd28 {
    unsigned int w0;
    unsigned int w1;
    unsigned int w2;
    unsigned int w3;
    unsigned int w4;
    unsigned char b;
};

// USA: func_ov025_021dcd28
ARM void CopyFiveWordsAndByte_021dcd28(struct FiveWordsAndByte_021dcd28* dst, struct FiveWordsAndByte_021dcd28* src) {
    dst->w0 = src->w0;
    dst->w1 = src->w1;
    dst->w2 = src->w2;
    dst->w3 = src->w3;
    dst->w4 = src->w4;
    dst->b = src->b;
}
