#include <globaldefs.h>

extern int data_02111824;

// USA: func_020cf864
ARM void WaitForFlagClear_020cf864(void) {
    while (*(volatile int*)&data_02111824 == 1) {}
}
