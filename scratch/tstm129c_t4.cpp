#include <globaldefs.h>

struct Pair { int lo, hi; };
struct Outer { int f0; Pair p1; Pair p2; int f5; };

ARM void TestStmT4(Outer* o, int a, int b) {
    o->f0 = b;
    Pair t1 = { a, 0 };
    o->p1 = t1;
    a = -a;
    Pair t2 = { a, b };
    o->p2 = t2;
    o->f5 = 0;
}
