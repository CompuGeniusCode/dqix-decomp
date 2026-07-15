#include <globaldefs.h>

struct Triple0215942c { int c, d, e; };
struct Struct0215942c { int pad; struct Triple0215942c t; };

extern "C" void func_ov001_02157964(void*, struct Triple0215942c);

// USA: func_ov001_0215942c
ARM int ForwardTripleFields_0215942c(struct Struct0215942c* a, void* b) {
    func_ov001_02157964((char*)b + 0x11c, a->t);
    return 0;
}
