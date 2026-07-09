#include <globaldefs.h>

struct Block9_0201ae8c { unsigned int v[9]; };
struct Block3_0201ae8c { unsigned int v[3]; };
struct Struct0201ae8c {
    struct Block9_0201ae8c a;   // 0x00
    struct Block3_0201ae8c b;   // 0x24
    unsigned int c;             // 0x30
};

// USA: func_0201ae8c
ARM struct Struct0201ae8c* CopyStruct0201ae8c(struct Struct0201ae8c* dst, struct Struct0201ae8c* src) {
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    return dst;
}
