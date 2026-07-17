#include <globaldefs.h>

int IsGlobal02290d10Set_02237eb0(void);
void SetField_022274c0_022274c0(void* fn);
void RunFieldDispatchThenSetHandler_0222b1f0(void);

// USA: func_ov031_0222b3b4
ARM void TransitionUnlessFlagSet_0222b3b4(void) {
    if (IsGlobal02290d10Set_02237eb0() != 0)
        return;
    SetField_022274c0_022274c0((void*)RunFieldDispatchThenSetHandler_0222b1f0);
}
