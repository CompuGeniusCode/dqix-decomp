#include <globaldefs.h>
struct Stride8_t { unsigned short v; unsigned char pad[6]; };
extern Stride8_t arrA[];
extern Stride8_t arrB[];
extern Stride8_t arrC[];
extern Stride8_t arrD[];
extern "C" void callee(unsigned short,unsigned short,unsigned short,unsigned short);
extern "C" ARM void test14(unsigned int i) {
    unsigned short a = arrA[(unsigned char)i].v;
    unsigned short b = arrB[(unsigned char)i].v;
    unsigned short c = arrC[(unsigned char)i].v;
    unsigned short d = arrD[(unsigned char)i].v;
    callee(a,b,c,d);
}
