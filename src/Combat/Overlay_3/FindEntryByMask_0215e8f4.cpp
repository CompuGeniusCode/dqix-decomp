#include <globaldefs.h>

struct ByteArray_0215e8f4 {
    char pad[8];
    unsigned char* data;
    char pad2[2];
    short count;
};

struct Self0215e8f4 {
    char pad0[4];
    struct ByteArray_0215e8f4* arr;
    char pad4[0x1e - 8];
    unsigned char mask;
};

// USA: func_ov003_0215e8f4
ARM void* FindEntryByMask_0215e8f4(struct Self0215e8f4* self) {
    struct ByteArray_0215e8f4* arr = self->arr;
    unsigned char mask = self->mask;
    unsigned char* p = arr->data;
    int count = arr->count;
    int i;
    for (i = 0; i < count; i++, p += 8) {
        if (*p & mask) {
            return p;
        }
    }
    return NULL;
}
