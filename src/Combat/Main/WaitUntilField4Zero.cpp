#include <globaldefs.h>

extern volatile int data_0210cf78[];

// USA: func_020b69f4
ARM void WaitUntilField4Zero(void) {
    while (data_0210cf78[1] != 0);
}
