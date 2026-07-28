#include <globaldefs.h>

// USA: func_02008da4  (semantic: CopySignDouble02008da4)
extern "C" ARM double func_02008da4(double x, double y) {
    unsigned int hx = ((unsigned int*)&x)[1];
    unsigned int hy = ((unsigned int*)&y)[1];
    ((unsigned int*)&x)[1] = (hx & 0x7fffffffu) | (hy & 0x80000000u);
    return x;
}
