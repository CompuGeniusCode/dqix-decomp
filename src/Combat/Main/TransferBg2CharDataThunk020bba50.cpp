#include <globaldefs.h>

extern "C" int LoadToMainBG2CharacterData(int, int, unsigned int);

// USA: func_020bba50
ARM int TransferBg2CharDataThunk020bba50(int arg0, int arg1, unsigned int arg2) {
    return LoadToMainBG2CharacterData(arg0, arg1, arg2);
}
