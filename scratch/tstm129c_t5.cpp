#include <globaldefs.h>

struct Range5 { int f0, f4, f8, fc, f10; };
struct Layout5 { Range5 r; int f14, f18, f1c, f20; };

THUMB void TestStmT5(Layout5* out, int a1, int a2) {
    Range5 tmp = { a2, a1, 0, -a1, a2 };
    out->r = tmp;
    out->f14 = 0;
    out->f18 = 0;
    out->f1c = 0;
    out->f20 = 0x1000;
}
