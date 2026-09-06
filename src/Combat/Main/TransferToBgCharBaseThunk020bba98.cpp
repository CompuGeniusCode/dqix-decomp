#include <globaldefs.h>

extern "C" ARM int LoadToMainBG2ScreenData(int arg0, int arg1, unsigned int arg2);

// USA: func_020bba98
ARM int TransferToBgCharBaseThunk020bba98(int arg0, int arg1, unsigned int arg2) {
    return LoadToMainBG2ScreenData(arg0, arg1, arg2);
}
