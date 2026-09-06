#include <globaldefs.h>

struct Word3_regtest_copy7 { unsigned int a, b, c; };

ARM void TestLoopCopy_regtest7(const Word3_regtest_copy7* src, Word3_regtest_copy7* dst) {
    int i;
    for (i = 0; i < 4; i++) {
        *dst++ = *src++;
    }
}
