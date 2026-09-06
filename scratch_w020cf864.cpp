#include <globaldefs.h>

extern volatile int data_02111824;

// USA: func_020cf864
ARM void SpinWaitFlag_020cf864(void) {
    volatile int* p = &data_02111824;
    do {
    } while (*p == 1);
}
