#include <globaldefs.h>

struct Word3_regtest_copy3 { unsigned int a, b, c; };

ARM void TestCopy2_regtest3(const Word3_regtest_copy3* src, Word3_regtest_copy3* dst) {
    dst[0] = src[0];
    dst[1] = src[1];
}
