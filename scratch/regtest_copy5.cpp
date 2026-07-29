#include <globaldefs.h>

struct Word4_regtest_copy5 { unsigned int a, b, c, d; };

ARM void TestCopy1_regtest5(const Word4_regtest_copy5* src, Word4_regtest_copy5* dst) {
    *dst = *src;
}
