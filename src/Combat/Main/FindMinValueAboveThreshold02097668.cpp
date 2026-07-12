#include <globaldefs.h>

struct Elem02097668 {
    unsigned char pad0[0x13];
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char markBit : 1;
    unsigned char bit3_7 : 5;
    unsigned char pad14[0x1a - 0x14];
    short value;
    unsigned char pad1c[0x20 - 0x1c];
};

struct Header02097668 {
    unsigned int w0;
    unsigned int count : 12;
    unsigned int w4_hi : 20;
    struct Elem02097668* arr;
};

// USA: func_02097668
ARM struct Elem02097668* FindMinValueAboveThreshold02097668(struct Header02097668* obj, int threshold) {
    unsigned short count = obj->count;
    struct Elem02097668* arr = obj->arr;
    short best = 0x7fff;
    struct Elem02097668* result = 0;
    unsigned short i;
    for (i = 0; i < count; i++) {
        struct Elem02097668* e = &arr[i];
        if (!e->markBit && e->bit0) {
            if (e->value > threshold && best > e->value) {
                best = e->value;
                result = e;
            }
        }
    }
    return result;
}
