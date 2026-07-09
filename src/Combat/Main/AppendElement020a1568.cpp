#include <globaldefs.h>

struct Elem020a1568 {
    unsigned int w0;
    unsigned int w1;
    unsigned int w2;
};

struct Array020a1568 {
    struct Elem020a1568* base;
    unsigned short capacity;
    unsigned short count;
};

// USA: func_020a1568
ARM void AppendElement020a1568(struct Array020a1568* arr, struct Elem020a1568* src) {
    unsigned short count;
    struct Elem020a1568* dst;
    if (src == NULL) {
        return;
    }
    count = arr->count;
    if (arr->capacity <= count) {
        return;
    }
    dst = &arr->base[count];
    dst->w0 = src->w0;
    dst->w1 = src->w1;
    dst->w2 = src->w2;
    arr->count++;
}
