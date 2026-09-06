#include <globaldefs.h>

extern "C" int LoadToMainBG1CharacterData(int, int, unsigned int);

// USA: func_020bba44
ARM int TransferBg1CharDataThunk020bba44(int arg0, int arg1, unsigned int arg2) {
    return LoadToMainBG1CharacterData(arg0, arg1, arg2);
}
