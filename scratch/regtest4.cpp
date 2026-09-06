#include <globaldefs.h>

extern "C" int helper(void*, const void*);
extern int g_data;

ARM void Test(const char* p0, unsigned int* p1, int p2, const char* p3) {
    if (p0 == 0) return;
    char buf[0x40];
    *p1 = 0;
    helper(buf, p0);
}
