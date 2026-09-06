#include <globaldefs.h>

extern "C" int LoadToMainBG0CharacterData(int, int, unsigned int);

// USA: func_020bba38
ARM int TransferBg0CharDataThunk020bba38(int arg0, int arg1, unsigned int arg2) {
    return LoadToMainBG0CharacterData(arg0, arg1, arg2);
}
