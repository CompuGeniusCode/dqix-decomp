#include <globaldefs.h>

extern "C" ARM int LoadToMainBG3ScreenData(int arg0, int arg1, unsigned int arg2);

// USA: func_020bbaa4
ARM int TransferBg3ScreenDataThunk020bbaa4(int arg0, int arg1, unsigned int arg2) {
    return LoadToMainBG3ScreenData(arg0, arg1, arg2);
}
