#include <globaldefs.h>

extern "C" int LoadToMainBG3CharacterData(int, int, unsigned int);

// USA: func_020bba5c
ARM int TransferToBg3CharThunk020bba5c(int arg0, int arg1, unsigned int arg2) {
    return LoadToMainBG3CharacterData(arg0, arg1, arg2);
}
