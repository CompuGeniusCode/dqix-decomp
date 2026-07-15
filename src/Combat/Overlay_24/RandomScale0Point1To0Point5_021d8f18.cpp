#include <globaldefs.h>
#include "System/Random.h"

// USA: func_ov024_021d8f18
ARM int RandomScale0Point1To0Point5_021d8f18(struct Random** rngPtr, int a1, int a2, int a3, int a4, int val) {
    struct Random* rng = *rngPtr;
    float f = NextRandomFloatBetween(rng, 0.1f, 0.5f);
    return (int)((float)val * f);
}
