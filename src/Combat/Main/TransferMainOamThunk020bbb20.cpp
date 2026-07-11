#include <globaldefs.h>

ARM int TransferMainOam(int arg0, int arg1, unsigned int arg2);

// USA: func_020bbb20
ARM int TransferMainOamThunk020bbb20(int arg0, int arg1, unsigned int arg2) {
    return TransferMainOam(arg0, arg1, arg2);
}
