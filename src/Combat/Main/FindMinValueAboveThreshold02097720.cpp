#include <globaldefs.h>

struct Elem02097720 {
    unsigned char pad0[0xe];
    short value;
    unsigned char pad10[0x13 - 0x10];
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char markBit : 1;
    unsigned char bit3_7 : 5;
    unsigned char pad14[0x20 - 0x14];
};

struct Header02097720 {
    unsigned int w0;
    unsigned int count : 12;
    unsigned int w4_hi : 20;
    struct Elem02097720* arr;
};

// USA: func_02097720
ARM struct Elem02097720* FindMinValueAboveThreshold02097720(struct Header02097720* obj, int threshold) {
    unsigned short count = obj->count;
    struct Elem02097720* arr = obj->arr;
    short best = 0x7fff;
    struct Elem02097720* result = 0;
    unsigned short i;
    for (i = 0; i < count; i++) {
        struct Elem02097720* e = &arr[i];
        if (!e->markBit && e->bit0) {
            if (e->value > threshold && best > e->value) {
                best = e->value;
                result = e;
            }
        }
    }
    return result;
}
