#include <globaldefs.h>

struct Word3_regtest10 { unsigned int a, b, c; };

ARM void TestTmpCopy_regtest10(const Word3_regtest10* src, Word3_regtest10* dst) {
    Word3_regtest10 t0 = *src++; *dst++ = t0;
    Word3_regtest10 t1 = *src++; *dst++ = t1;
    Word3_regtest10 t2 = *src++; *dst++ = t2;
    Word3_regtest10 t3 = *src++; *dst++ = t3;
}
