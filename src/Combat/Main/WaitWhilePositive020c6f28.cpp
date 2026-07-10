#include <globaldefs.h>

extern "C" void WaitByLoop(int);
extern "C" int func_020c6f28(int, int, int, int);

// USA: func_020c6e48
ARM void WaitWhilePositive020c6f28(int a, int b, int c, int d) {
    if (func_020c6f28(a, b, c, d) > 0) {
        do {
            WaitByLoop(0x400);
        } while (func_020c6f28(a, b, c, d) > 0);
    }
}
