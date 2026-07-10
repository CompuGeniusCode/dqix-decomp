#include <globaldefs.h>

extern "C" void WaitByLoop(int);
extern "C" int func_020cae94(int, int, int);

// USA: func_020d1294
ARM void WaitWhileChannel0xEBusy(int a, int b) {
    if (func_020cae94(0xe, a, 0) != 0) {
        do {
            WaitByLoop(b);
        } while (func_020cae94(0xe, a, 0) != 0);
    }
}
