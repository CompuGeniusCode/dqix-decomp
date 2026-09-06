#include <globaldefs.h>

extern "C" int func_020d217c(int, int, int, int, int);

// USA: func_020d1ebc
ARM int EnqueueEvent0x09(int a, int b, int c) {
    return func_020d217c(0x9, a, b, c, 0);
}
