#include <globaldefs.h>
#pragma optimize_for_size off

ARM void TestOptSize_regtest11(unsigned short val, char* dst, int n) {
    int i = 0;
    while (i < n) {
        if (i < n) *(unsigned short*)(dst + i) = val;
        if (i < n) i += 2;
    }
}
