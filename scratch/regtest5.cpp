#include <globaldefs.h>

extern "C" int helper(void*, const void*);
extern "C" void* helper2(const void*, void*, unsigned int*);
extern int g_data;

ARM void* Test(const char* p0, unsigned int* p1, int p2, const char* p3) {
    if (p0 == 0) return 0;
    char buf[0x40];
    *p1 = 0;
    helper(buf, p0);
    if (p3 == 0) {
        helper2(buf, &g_data, p1);
        return 0;
    }
    return 0;
}
