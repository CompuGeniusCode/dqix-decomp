#include <globaldefs.h>

struct S021719c0 { char pad[0x1a4]; int field[0x93]; };

// USA: func_ov000_021719c0
ARM short CountNonZero021719c0(struct S021719c0* s) {
    short count = 0;
    int i;
    for (i = 0; i < 0x93; i++) {
        if (s->field[i] != 0) count++;
    }
    return count;
}
