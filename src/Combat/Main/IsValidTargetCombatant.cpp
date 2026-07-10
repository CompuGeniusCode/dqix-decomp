#include <globaldefs.h>

struct TargetObj02088418 {
    unsigned char pad00[0x14];
    unsigned int flags14;
    unsigned char pad18[0x22 - 0x18];
    unsigned short : 2;
    unsigned short field22 : 4;
    unsigned short : 10;
};

// USA: func_02088418
ARM int IsValidTargetCombatant(struct TargetObj02088418* c, int index, int actionId) {
    unsigned int flags = c->flags14;
    if (flags & 0x1) return 0;
    if ((flags & 0x1000000) && actionId != 0x1fc && actionId != 0x20f) return 0;
    if (flags & 0x8) return 0;
    if (flags & 0x80000) {
        if (index == c->field22) return 0;
    }
    return 1;
}
