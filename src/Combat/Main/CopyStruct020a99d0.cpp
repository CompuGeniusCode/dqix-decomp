#include <globaldefs.h>

struct Half70_a99d0 { unsigned short v[70]; };
struct Byte564_a99d0 { unsigned char v[564]; };
struct Half6_a99d0 { unsigned short v[6]; };
struct Byte102_a99d0 { unsigned char v[102]; };

struct Struct020a99d0 {
    struct Half70_a99d0 a;
    struct Byte564_a99d0 b;
    struct Half6_a99d0 c;
    struct Byte102_a99d0 d;
    unsigned char e;
};

// USA: func_020a99d0
ARM void CopyStruct020a99d0(struct Struct020a99d0* dst, struct Struct020a99d0* src) {
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->d = src->d;
    dst->e = src->e;
}
