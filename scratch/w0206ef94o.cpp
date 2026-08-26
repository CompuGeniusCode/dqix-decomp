#include <globaldefs.h>

struct S0206ef94 { char pad[8]; int field8; };

// USA: func_0206ef94
ARM int GetIndexOrDefault_0206ef94(struct S0206ef94* obj, int idx, int fallback) {
    idx = -1;
    int state = 1;
    int savedIdx = idx;
    if (savedIdx != idx) {
        if (obj->field8 != 0) {
            state = 0;
        }
    }
    int result = fallback;
    if (state == 0) {
        result = obj->field8 + savedIdx;
    }
    return result;
}
