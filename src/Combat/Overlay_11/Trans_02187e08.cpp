#include <globaldefs.h>

extern "C" unsigned int _Z28SetFieldConditional_021849e0P14Fields021849e0t(unsigned int, unsigned int);
extern "C" unsigned int func_ov017_021b2164();

// USA: func_ov011_02187e08  (semantic: Trans_02187e08)
extern "C" ARM unsigned int func_ov011_02187e08(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    r0 = (unsigned int)func_ov017_021b2164();
    r1 = 0x0;
    r0 = (unsigned int)_Z28SetFieldConditional_021849e0P14Fields021849e0t(r0, r1);
    r0 = 0x1;
    return r0;
}
