#include <globaldefs.h>

void WaitWhileChannelBusy(int);
extern "C" void func_020c9be0(void);

// USA: func_020d192c
ARM void SpinDrainAfterWait(void) {
    WaitWhileChannelBusy(2);
    func_020c9be0();
}
