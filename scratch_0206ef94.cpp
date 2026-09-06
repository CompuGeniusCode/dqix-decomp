#include <globaldefs.h>

struct S0206ef94 { char pad[8]; int field8; };

// USA: func_0206ef94
ARM int GetIndexOrDefault_0206ef94(struct S0206ef94* obj, int idx, int def) {
    int state = 1;
    if (idx != state - 2) {
        if (obj->field8 != 0) {
            state = 0;
        }
    }
    if (state == 0) {
        def = obj->field8 + idx;
    }
    return def;
}
