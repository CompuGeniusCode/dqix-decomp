#include <globaldefs.h>
#pragma optimize_for_size off

struct Obj020bc084 {
    int field0;
};

// USA: func_020bc084
ARM void ClearFieldAndNullSlot020bc084(struct Obj020bc084** slot) {
    if (*(int*)slot == 0) {
        return;
    }
    (*slot)->field0 = 0;
    *slot = NULL;
}
