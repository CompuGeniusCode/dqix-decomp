#include <globaldefs.h>

extern char data_02107800;

// USA: func_020429bc
ARM int GetField0x10IfArg8(int x) {
    int r = 0;
    if (x == 8) r = *(int*)(&data_02107800 + 0x10);
    return r;
}
