#include <globaldefs.h>

struct Variant02030b0c {
    int tag;
    union {
        int i;
        float f;
    } u;
};

extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

struct VariantArray0201f894 {
    struct Variant02030b0c items[6];
};

// USA: func_0201f894
ARM int ValidateVariantArray0201f894(struct VariantArray0201f894* s) {
    _ZNK6Script9Parameter5ToIntEv(&s->items[0]);
    _ZNK6Script9Parameter5ToIntEv(&s->items[1]);
    _ZNK6Script9Parameter5ToIntEv(&s->items[2]);
    _ZNK6Script9Parameter5ToIntEv(&s->items[3]);
    _ZNK6Script9Parameter5ToIntEv(&s->items[4]);
    _ZNK6Script9Parameter5ToIntEv(&s->items[5]);
    return 1;
}
