#include <globaldefs.h>

extern char data_0210cf88;

// USA: func_020bb92c
ARM void WriteGlobalPair020bb92c(int* src) {
    *(int*)(&data_0210cf88 + 0x0) = src[0];
    *(int*)(&data_0210cf88 + 0x4) = src[1];
}
