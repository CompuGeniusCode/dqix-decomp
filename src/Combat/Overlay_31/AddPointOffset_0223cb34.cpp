#include <globaldefs.h>

struct Point16_0223cb34 { unsigned short x, y; };
struct PointPair16_0223cb34 { unsigned short x, y, x2, y2; };

// USA: func_ov031_0223cb34  (semantic: AddPointOffset_0223cb34)
extern "C" ARM void func_ov031_0223cb34(Point16_0223cb34* a, Point16_0223cb34* b, PointPair16_0223cb34* out) {
    out->x = a->x;
    out->y = a->y;
    out->x2 = a->x + b->x;
    out->y2 = a->y + b->y;
}
