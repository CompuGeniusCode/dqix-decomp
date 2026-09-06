#include <globaldefs.h>

struct Pair { int lo, hi; };
struct Outer { int f0; Pair p; };

THUMB void TestStmT3(Outer* o, Pair v) {
    o->p = v;
}
