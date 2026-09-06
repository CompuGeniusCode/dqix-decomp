#include <globaldefs.h>

struct Word3_regtest_copy2 { unsigned int a, b, c; };

ARM void TestCopy2_regtest(const Word3_regtest_copy2* src, Word3_regtest_copy2* dst) {
    *dst++ = *src++;
    *dst++ = *src++;
}
