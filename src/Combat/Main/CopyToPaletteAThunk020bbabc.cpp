#include <globaldefs.h>

ARM void CopyToPaletteA(int src, int dstOffset, unsigned int size);

// USA: func_020bbabc
ARM void CopyToPaletteAThunk020bbabc(int src, int dstOffset, unsigned int size) {
    CopyToPaletteA(src, dstOffset, size);
}
