#include <globaldefs.h>

struct Pair { int lo, hi; };
struct Outer { Pair p; };

ARM void TestStm(Outer* o, int a, int b) {
    Pair t = { a, b };
    o->p = t;
}
