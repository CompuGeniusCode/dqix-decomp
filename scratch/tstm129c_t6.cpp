#include <globaldefs.h>

struct G0 { int f0; };
struct G1 { int f0, f1; };
struct G2 { int f0, f1; };
struct Layout { G0 g0; G1 g1; G2 g2; int f14, f18, f1c, f20; };

THUMB void TestStmT6(Layout* out, int a1, int a2) {
    G0 v0 = { a2 };
    out->g0 = v0;
    G1 v1 = { a1, 0 };
    out->g1 = v1;
    a1 = -a1;
    G2 v2 = { a1, a2 };
    out->g2 = v2;
    out->f14 = 0;
    out->f18 = 0;
    out->f1c = 0;
    out->f20 = 0x1000;
}
