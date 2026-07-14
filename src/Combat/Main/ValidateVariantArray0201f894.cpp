#include <globaldefs.h>

struct Variant02030b0c {
    int tag;
    union {
        int i;
        float f;
    } u;
};

int GetIntFromVariant02030b0c(struct Variant02030b0c* p);

struct VariantArray0201f894 {
    struct Variant02030b0c items[6];
};

// USA: func_0201f894
ARM int ValidateVariantArray0201f894(struct VariantArray0201f894* s) {
    GetIntFromVariant02030b0c(&s->items[0]);
    GetIntFromVariant02030b0c(&s->items[1]);
    GetIntFromVariant02030b0c(&s->items[2]);
    GetIntFromVariant02030b0c(&s->items[3]);
    GetIntFromVariant02030b0c(&s->items[4]);
    GetIntFromVariant02030b0c(&s->items[5]);
    return 1;
}
