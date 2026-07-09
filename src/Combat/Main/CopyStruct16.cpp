#include <globaldefs.h>

struct Inner3_0201d474 {
    int v[3];
};

struct Struct0201d474 {
    struct Inner3_0201d474 head;
    int tail;
};

// USA: func_0201d474
ARM struct Struct0201d474* CopyStruct16(struct Struct0201d474* dst, struct Struct0201d474* src) {
    dst->head = src->head;
    dst->tail = src->tail;
    return dst;
}
