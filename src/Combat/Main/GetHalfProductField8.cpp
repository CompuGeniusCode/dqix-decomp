#include <globaldefs.h>

struct Dims020e1288 {
    unsigned char pad0[0xa];
    unsigned char w;
    unsigned char h;
};

struct HasDims020e1288 {
    unsigned char pad0[8];
    struct Dims020e1288* dims;
};

// USA: func_020e1288
ARM int GetHalfProductField8(struct HasDims020e1288* obj) {
    struct Dims020e1288* d = obj->dims;
    if (d != NULL) {
        return (d->w * d->h) >> 1;
    }
    return 0;
}
