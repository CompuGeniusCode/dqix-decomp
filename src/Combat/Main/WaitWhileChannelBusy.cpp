#include <globaldefs.h>

extern "C" void WaitByLoop(int);
extern "C" int func_020cae94(int, int, int);

// USA: func_020d1564
ARM void WaitWhileChannelBusy(int a) {
    if (func_020cae94(0xd, a, 0) != 0) {
        do {
            WaitByLoop(1);
        } while (func_020cae94(0xd, a, 0) != 0);
    }
}
