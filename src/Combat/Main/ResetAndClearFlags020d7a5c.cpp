#include <globaldefs.h>
#include "std_library_functions.h"

struct ResetObj020d7a5c {
    unsigned char pad[0x150];
    unsigned char flags;
    unsigned char pad2;
    unsigned short field152;
};

// USA: func_020d7a5c
ARM void ResetAndClearFlags020d7a5c(struct ResetObj020d7a5c* o) {
    memset(o, 0, 0x150);
    o->flags &= ~0x3f;
    o->field152 = 0;
    o->flags &= ~0x40;
    o->flags &= ~0x80;
}
