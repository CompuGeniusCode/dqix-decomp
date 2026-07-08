#include <globaldefs.h>

struct ResetStruct {
    int w0;
    int w4;
    int w8;
    int wc;
    int w10;
    int w14;
    int w18;
    int w1c;
    int w20;
    int w24;
    int w28;
    char pad[0x400];
    unsigned char b42c;
};

// USA: func_02030634
ARM int ResetFieldsReturnTrue(struct ResetStruct* s) {
    s->w0 = 0;
    s->w8 = 0;
    s->wc = 0;
    s->w10 = 0;
    s->w14 = 0;
    s->w18 = 0;
    s->w1c = 0;
    s->w20 = 0;
    s->w24 = 0;
    s->w28 = 0;
    s->b42c = 0;
    return 1;
}
