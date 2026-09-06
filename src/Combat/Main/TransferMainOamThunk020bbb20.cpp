#include <globaldefs.h>

extern "C" ARM int LoadToMainOAM(int arg0, int arg1, unsigned int arg2);

// USA: func_020bbb20
ARM int TransferMainOamThunk020bbb20(int arg0, int arg1, unsigned int arg2) {
    return LoadToMainOAM(arg0, arg1, arg2);
}
