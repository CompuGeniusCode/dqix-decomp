#include <globaldefs.h>

extern "C" void WaitByLoop(int);
extern "C" void func_020c6954(int, int);

// USA: func_020c9820
ARM void DelayThenSyncBit0(void) {
    WaitByLoop(1);
    func_020c6954(1, 1);
}
