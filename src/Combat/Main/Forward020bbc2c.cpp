#include <globaldefs.h>

extern "C" int LoadToSubObjVRAM(int, int, unsigned int);

// USA: func_020bbc2c
ARM int Forward020bbc2c(int a, int b, unsigned int c) {
    return LoadToSubObjVRAM(a, b, c);
}
