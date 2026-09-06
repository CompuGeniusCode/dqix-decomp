#include <globaldefs.h>

extern "C" ARM int LoadToMainObjStandardPalette(int arg0, int arg1, unsigned int arg2);

// USA: func_020bbab0
ARM int TransferMainObjPaletteThunk020bbab0(int arg0, int arg1, unsigned int arg2) {
    return LoadToMainObjStandardPalette(arg0, arg1, arg2);
}
