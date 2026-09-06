#include <globaldefs.h>

extern char data_0210cf88;

// USA: func_020bb948
ARM void ResetGlobalState020bb948(void) {
    *(int*)(&data_0210cf88 + 0x0) = 0;
    *(int*)(&data_0210cf88 + 0x4) = *(int*)(&data_0210cf88 + 0x8);
}
