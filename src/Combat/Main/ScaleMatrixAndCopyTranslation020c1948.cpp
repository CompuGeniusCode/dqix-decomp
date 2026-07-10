#include <globaldefs.h>

void ScaleMatrixRows020c11a4(int* src, int* dst, int scaleX, int scaleY, int scaleZ);

// USA: func_020c1948
ARM void ScaleMatrixAndCopyTranslation020c1948(int* src, int* dst, int scaleX, int scaleY, int scaleZ) {
    ScaleMatrixRows020c11a4(src, dst, scaleX, scaleY, scaleZ);
    dst[9] = src[9];
    dst[10] = src[10];
    dst[11] = src[11];
}
