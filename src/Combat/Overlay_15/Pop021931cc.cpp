#include <globaldefs.h>

struct Owner_021931cc { char pad[0x1a8]; int values[32]; int count; };

// USA: func_ov015_021931cc
ARM int Pop021931cc(struct Owner_021931cc* o) {
    int n = o->count;
    if (n <= 0)
        return -1;
    n = n - 1;
    o->count = n;
    int v = o->values[n];
    o->values[n] = -1;
    return v;
}
