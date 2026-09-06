#include <globaldefs.h>

extern "C" int LoadToSubOAM(int, int, unsigned int);

// USA: func_020bbc20
ARM int Forward020bbc20(int a, int b, unsigned int c) {
    return LoadToSubOAM(a, b, c);
}
