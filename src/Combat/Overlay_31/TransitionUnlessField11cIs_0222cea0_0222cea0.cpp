#include <globaldefs.h>

unsigned char GetField11c_02223fa0(void);
void SetField_022274c0_022274c0(void* fn);
void CallStubPair_0222cec0(void);

// USA: func_ov031_0222cea0
ARM void TransitionUnlessField11cIs_0222cea0_0222cea0(void) {
    if (GetField11c_02223fa0() == 0xff)
        return;
    SetField_022274c0_022274c0((void*)CallStubPair_0222cec0);
}
