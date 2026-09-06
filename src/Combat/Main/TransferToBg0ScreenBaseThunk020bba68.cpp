#include <globaldefs.h>

extern "C" int LoadToMainBG0ScreenData(int, int, unsigned int);

// USA: func_020bba68
ARM int TransferToBg0ScreenBaseThunk020bba68(int arg0, int arg1, unsigned int arg2) {
    return LoadToMainBG0ScreenData(arg0, arg1, arg2);
}
