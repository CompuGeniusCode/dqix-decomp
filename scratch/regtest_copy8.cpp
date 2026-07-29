#include <globaldefs.h>

ARM void TestScalarPostInc_regtest8(const unsigned int* src, unsigned int* dst) {
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
}
