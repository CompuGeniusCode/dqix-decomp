#include <globaldefs.h>
#pragma optimize_for_size off

// USA: func_ov031_0221cfc4  (semantic: BitwiseCompute_0221cfc4)
extern "C" THUMB unsigned int func_ov031_0221cfc4(unsigned int a, unsigned int b) {
    unsigned int ab = a & b;
    unsigned int notb = ~b;
    unsigned int t = (a & notb) + 1;
    t = t | ab;
    unsigned int u = notb | ab;
    if (t < u)
        return t;
    return 1 | ab;
}
