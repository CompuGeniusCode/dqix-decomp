#include <globaldefs.h>

struct Bytes9_02019f24 { unsigned char v[9]; };
struct Bytes5_02019f24 { unsigned char v[5]; };
struct Struct02019f24 {
    unsigned short a;
    struct Bytes9_02019f24 b;
    struct Bytes5_02019f24 c;
};

// USA: func_02019f24
ARM struct Struct02019f24* CopyStruct02019f24(struct Struct02019f24* dst, struct Struct02019f24* src) {
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    return dst;
}
