#include <globaldefs.h>

extern "C" int LoadToMainBG1ScreenData(int, int, unsigned int);

// USA: func_020bba74
ARM int Func020c5b98Thunk020bba74(int arg0, int arg1, unsigned int arg2) {
    return LoadToMainBG1ScreenData(arg0, arg1, arg2);
}
