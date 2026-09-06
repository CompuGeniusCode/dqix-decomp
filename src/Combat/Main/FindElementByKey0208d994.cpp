#include <globaldefs.h>

struct Elem0208d994 {
    short h0;
    int w4;
    int w8;
    int wc;
    int w10;
    int w14;
};

struct List0208d994 {
    struct Elem0208d994* base;
    short count;
};

// USA: func_0208d994
ARM struct Elem0208d994* FindElementByKey0208d994(struct List0208d994 *l, int key) {
    short i;
    if (key < 0) return NULL;
    for (i = 0; i < l->count; i++) {
        if (key == l->base[i].h0) return &l->base[i];
    }
    return NULL;
}
