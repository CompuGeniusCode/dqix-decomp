#include <globaldefs.h>

unsigned char GetField60_02225c24(void);
void SetField_022274c0_022274c0(void* fn);
void CallStubPair_0222da50(void);

// USA: func_ov031_0222da30
ARM void TransitionUnlessField60Is_0222da30_0222da30(void) {
    if (GetField60_02225c24() == 0x1f)
        return;
    SetField_022274c0_022274c0((void*)CallStubPair_0222da50);
}
