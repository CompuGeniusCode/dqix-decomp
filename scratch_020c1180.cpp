#include <globaldefs.h>

struct Vec2_020c1180 { int x, y; };
struct Mtx33_020c1180 { Vec2_020c1180 rows[4]; int m8; };

// USA: func_020c1180
ARM void SetIdentityMatrix33_020c1180(Mtx33_020c1180* m) {
    m->m8 = 0x1000;
    Vec2_020c1180 a; a.x = 0x1000; a.y = 0;
    Vec2_020c1180 b; b.x = 0; b.y = 0;
    Vec2_020c1180* p = m->rows;
    *p++ = a;
    *p++ = b;
    *p++ = a;
    *p++ = b;
}
