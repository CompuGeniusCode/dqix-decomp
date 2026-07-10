#include <globaldefs.h>

extern int data_02107800;

// USA: func_020421a0
ARM int GetGlobalField0x1c020421a0() {
    return *(int*)((char*)&data_02107800 + 0x1c);
}
