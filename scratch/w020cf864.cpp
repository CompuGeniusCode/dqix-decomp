#include <globaldefs.h>

extern volatile int data_02111824;

// USA: func_020cf864
ARM void SpinWait020cf864(void) {
    while (data_02111824 == 1) {}
}
