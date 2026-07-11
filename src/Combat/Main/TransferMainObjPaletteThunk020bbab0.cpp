#include <globaldefs.h>

ARM int TransferMainObjPalette(int arg0, int arg1, unsigned int arg2);

// USA: func_020bbab0
ARM int TransferMainObjPaletteThunk020bbab0(int arg0, int arg1, unsigned int arg2) {
    return TransferMainObjPalette(arg0, arg1, arg2);
}
