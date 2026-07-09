#include <globaldefs.h>

struct S020d9fb4 { unsigned int w0; unsigned int w4; unsigned short flags; };

// USA: func_020d9fb4
ARM void SetFlagBit020d9fb4(struct S020d9fb4* s, int bit) {
    s->flags |= 1 << bit;
}
