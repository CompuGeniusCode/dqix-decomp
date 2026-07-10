#include <globaldefs.h>

extern char data_02107800;

// USA: func_020429d4
ARM int GetData02107800Word0(void) {
    return *(int*)(&data_02107800);
}
