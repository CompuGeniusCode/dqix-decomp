#include <globaldefs.h>

struct Elem02097798 {
    unsigned char pad0[0x13];
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char markBit : 1;
    unsigned char bit3_7 : 5;
    unsigned char pad14[0x1a - 0x14];
    short order;
    unsigned char pad1c[0x20 - 0x1c];
};

struct Header02097798 {
    unsigned int w0;
    unsigned int count : 12;
    unsigned int w4_hi : 20;
    struct Elem02097798* arr;
};

// USA: func_02097798
ARM void MarkDuplicateOrders02097798(struct Header02097798* obj) {
    unsigned short count = obj->count;
    struct Elem02097798* arr = obj->arr;
    short ord;
    unsigned short i;
    unsigned short j;
    unsigned short limit = count - 1;
    for (i = 0; i < limit; i++) {
        struct Elem02097798* e = &arr[i];
        if (e->order <= 0) {
            e->markBit = 1;
        }
        if (!e->markBit) {
            ord = e->order;
            for (j = i + 1; j < count; j++) {
                if (arr[j].order == ord) {
                    arr[j].markBit = 1;
                }
            }
        }
    }
}
