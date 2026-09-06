#include <globaldefs.h>

static inline unsigned int Reinterp(float f) {
    return (unsigned int&)f;
}

// USA: func_ov001_0215af34
ARM unsigned int CastTest3(float c) {
    return Reinterp(c);
}
