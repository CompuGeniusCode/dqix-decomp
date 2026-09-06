#include <globaldefs.h>

extern "C" ARM int LoadToMainBG3ScreenData(int arg0, int arg1, unsigned int arg2);

// USA: func_020bba8c
ARM int TransferBg3ScreenDataThunk020bba8c(int arg0, int arg1, unsigned int arg2) {
    return LoadToMainBG3ScreenData(arg0, arg1, arg2);
}
