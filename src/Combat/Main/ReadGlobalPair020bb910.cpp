#include <globaldefs.h>

extern char data_0210cf88;

// USA: func_020bb910
ARM void ReadGlobalPair020bb910(int* dst) {
    dst[0] = *(int*)(&data_0210cf88 + 0x0);
    dst[1] = *(int*)(&data_0210cf88 + 0x4);
}
