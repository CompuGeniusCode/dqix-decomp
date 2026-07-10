#include <globaldefs.h>

extern "C" int func_020cae94(int, int, int);

// USA: func_020d2880
ARM void WaitUntilChannel7Ready() {
    while (func_020cae94(7, 0, 0) < 0)
        ;
}
