#include <globaldefs.h>

struct S02171698 { char pad[0x9c]; int field[0x42]; };

// USA: func_ov000_02171698
ARM signed char CountNonZero02171698(struct S02171698* s) {
    signed char count = 0;
    int i;
    for (i = 0; i < 0x42; i++) {
        if (s->field[i] != 0) count++;
    }
    return count;
}
