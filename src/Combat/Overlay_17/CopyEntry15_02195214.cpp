#include <globaldefs.h>

struct Mid12_02195214 { unsigned char v[12]; };
struct Entry15_02195214 {
    unsigned char a;
    unsigned char b;
    Mid12_02195214 mid;
    unsigned char e;
};

// USA: func_ov017_02195214  (semantic: CopyEntry15_02195214)
extern "C" ARM void func_ov017_02195214(Entry15_02195214* dst, Entry15_02195214* src) {
    dst->a = src->a;
    dst->b = src->b;
    dst->mid = src->mid;
    dst->e = src->e;
}
