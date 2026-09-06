#include <globaldefs.h>

struct Obj021754e0 { char pad[0x43c]; unsigned char flags; };

extern "C" struct Obj021754e0* func_ov000_02161318(int, int);

// USA: func_ov000_021754e0
ARM void SetFlag0x2_021754e0(int a, int b) {
    struct Obj021754e0* p = func_ov000_02161318(a, b);
    if (p) {
        p->flags |= 0x2;
    }
}
