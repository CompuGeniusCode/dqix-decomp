#include <globaldefs.h>

extern "C" int helper(void*, const void*);
extern "C" void* helper2(const void*, void*, unsigned int*);
extern "C" void* helper3(const void*, const void*, unsigned int*);
extern int g_data;

ARM void* Test(const char* p0, unsigned int* p1, int p2, const char* p3) {
    if (p0 == 0) return 0;
    char buf[0x40];
    *p1 = p2 & 0;
    helper(buf, p0);
    if (p3 == 0) {
        helper2(buf, &g_data, p1);
        if (*p1 == 0) goto ret0;
        return &g_data;
    }
    {
        void* result = helper3(p3, buf, p1);
        if (result != 0) return result;
    }
ret0:
    return 0;
}
