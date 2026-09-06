#include <globaldefs.h>

struct Entry0215e790 {
    short f0;
    short f2;
    int f4;
    int f8;
    unsigned char fc;
    unsigned char fd;
    unsigned char fe;
    unsigned char ff;
    short f10;
    unsigned char f12;
    unsigned char f13;
};

struct Self0215e790 {
    struct Entry0215e790* array;
    short capacity;
    short count;
};

// USA: func_ov003_0215e790
ARM void AppendEntryToArray_0215e790(struct Self0215e790* self, struct Entry0215e790* src) {
    if (self->array == NULL) {
        return;
    }
    if (self->capacity <= self->count) {
        return;
    }
    struct Entry0215e790* dst = &self->array[self->count];
    dst->f0 = src->f0;
    dst->f2 = src->f2;
    dst->f4 = src->f4;
    dst->f8 = src->f8;
    dst->fc = src->fc;
    dst->fd = src->fd;
    dst->fe = src->fe;
    dst->ff = src->ff;
    dst->f10 = src->f10;
    dst->f12 = src->f12;
    dst->f13 = src->f13;
    self->count++;
}
