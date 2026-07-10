#include <globaldefs.h>

extern "C" void func_02073240(int);

// USA: func_020732a8
ARM void CallFuncForEachOfFour(void) {
    int i;
    for (i = 0; i < 4; i++) {
        func_02073240(i);
    }
}
