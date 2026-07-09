#include <globaldefs.h>
struct Inner0205e3ec { unsigned int v[4]; };
struct Struct0205e3ec { unsigned char a; unsigned char b; unsigned char pad[2]; struct Inner0205e3ec mid; };
// USA: func_0205e3ec
ARM struct Struct0205e3ec* CopyStruct0205e3ec(struct Struct0205e3ec* dst, struct Struct0205e3ec* src) {
    dst->a = src->a;
    dst->b = src->b;
    dst->mid = src->mid;
    return dst;
}
