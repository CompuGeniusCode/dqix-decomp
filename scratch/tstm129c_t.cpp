#include <globaldefs.h>

struct Pair { int lo, hi; };
struct Outer { Pair p; };

THUMB void TestStmT(Outer* o, int a, int b) {
    Pair t = { a, b };
    o->p = t;
}
