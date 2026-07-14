#include <globaldefs.h>

int SendCommandToArm7(int, int, bool);

// USA: func_020d2880
ARM void WaitUntilChannel7Ready() {
    while (SendCommandToArm7(7, 0, 0) < 0)
        ;
}
