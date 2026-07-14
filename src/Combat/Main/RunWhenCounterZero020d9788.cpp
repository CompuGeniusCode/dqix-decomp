#include <globaldefs.h>

extern char data_0214e4a8;
void SleepCurrentContext(unsigned int arg);

// USA: func_020d9788
ARM void RunWhenCounterZero020d9788(int arg) {
    if (*(int*)(&data_0214e4a8 + 4) != 0) return;
    SleepCurrentContext(arg);
}
