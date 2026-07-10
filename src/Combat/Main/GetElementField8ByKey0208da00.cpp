#include <globaldefs.h>

struct Elem0208da00 {
    short h0;
    int w4;
    int w8;
    int wc;
    int w10;
    int w14;
};

struct List0208d994 {
    struct Elem0208da00* base;
    short count;
};

extern struct Elem0208da00* FindElementByKey0208d994(struct List0208d994* l, int key);

// USA: func_0208da00
ARM int GetElementField8ByKey0208da00(struct List0208d994* list, int key) {
    struct Elem0208da00* e = FindElementByKey0208d994(list, key);
    return e ? e->w8 : 0;
}
