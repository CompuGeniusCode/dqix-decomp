#include <globaldefs.h>

extern "C" void fix32_QueueComputeQuotient(unsigned int numerHi, unsigned int denomLo);
extern "C" int fix32_GetDivisionResult(void);

// USA: func_020c2bf4
extern "C" ARM int fix32_Divide(unsigned int numerHi, unsigned int denomLo) {
    fix32_QueueComputeQuotient(numerHi, denomLo);
    return fix32_GetDivisionResult();
}
