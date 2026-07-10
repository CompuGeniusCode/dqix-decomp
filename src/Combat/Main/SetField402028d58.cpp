#include <globaldefs.h>

extern int data_020fe9a4;

// USA: func_02028d58
ARM void SetField402028d58(int value) {
    (&data_020fe9a4)[1] = value;
}
