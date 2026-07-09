#include <globaldefs.h>

struct C7_020999f0 { char v[7]; };

struct Elem020999f0 {
    unsigned short f0;
    unsigned short f2;
    unsigned char f4;
    struct C7_020999f0 f5;
    unsigned char fc;
    unsigned char fd;
    unsigned char fe;
    unsigned char pad;
};

struct List020999f0 {
    struct Elem020999f0* data;
    int count;
    int cap;
};

// USA: func_020999f0
ARM void AppendElement020999f0(struct List020999f0* list, struct Elem020999f0* src) {
    int i = list->count;
    if (list->cap <= i) return;
    list->count = i + 1;
    {
        struct Elem020999f0* elem = &list->data[i];
        elem->f0 = src->f0;
        elem->f2 = src->f2;
        elem->f4 = src->f4;
        elem->f5 = src->f5;
        elem->fc = src->fc;
        elem->fd = src->fd;
        elem->fe = src->fe;
    }
}
