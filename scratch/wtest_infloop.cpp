#include <globaldefs.h>

ARM void TestInfLoop(int* p) {
    for (;;) {
        if (*p == 0) {
            *p = 1;
            return;
        }
        *p = *p - 1;
    }
}
