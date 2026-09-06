#include <globaldefs.h>

THUMB void TestStmT2(int* p, int a, int b) {
    *p++ = a;
    *p++ = b;
}
