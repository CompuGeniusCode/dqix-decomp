#include <globaldefs.h>

ARM unsigned char GetField11c_02223fa0(void);
ARM void SetField_022274c0_022274c0(int);
ARM void CallStubPair_0222cec0(void);

// USA: func_ov031_0222cea0
extern "C" ARM void func_ov031_0222cea0(void) {
    if (GetField11c_02223fa0() == 0xff) return;
    SetField_022274c0_022274c0((int)CallStubPair_0222cec0);
}
