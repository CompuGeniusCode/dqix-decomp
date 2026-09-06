#include <globaldefs.h>

struct S0206ef94m { int pad1; int pad2; int field8; };

// USA: func_0206ef94
ARM int GetFieldSumOrDefault_0206ef94(S0206ef94m* obj, int idx, int fallback) {
    int result = fallback;
    int flag = 1;
    if (idx != -1) {
        if (obj->field8 != 0) flag = 0;
    }
    if (!flag) result = obj->field8 + idx;
    return result;
}
