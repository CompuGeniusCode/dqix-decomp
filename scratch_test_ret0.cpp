#include <globaldefs.h>
extern "C" void* cleanup(void*);
extern "C" void* other1(void*, int);
extern "C" int fret0(void* p, int q) {
    void* x = other1(p, q);
    if (!x) {
        cleanup(p);
        return 0;
    }
    cleanup(p);
    return 0;
}
