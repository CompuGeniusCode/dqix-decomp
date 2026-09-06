#include <globaldefs.h>
extern "C" void* g(void*, int);
extern "C" void* cleanup(void*);
extern "C" int fp2(void* a) {
    void* r1 = g(a, 1);
    void* r2 = g(a, 2);
    void* r3 = g(a, 3);
    void* r4v = g(a, 4);
    if (r1) {
        g(r1, (int)r2);
        g(r3, (int)r4v);
    }
    int result = 0;
    cleanup(a);
    return result;
}
