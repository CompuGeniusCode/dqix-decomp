#include <globaldefs.h>
extern "C" void* cleanup(void*);
extern "C" void* other1(void*, int);
extern "C" int fret0b(void* p, int q, void* localbuf) {
    void* x = other1(p, q);
    if (!x) {
        void* result = 0;
        cleanup(localbuf);
        return (int)result;
    }
    // big unrelated block to prevent merge
    other1(p, 1); other1(p,2); other1(p,3); other1(p,4); other1(p,5);
    void* result = 0;
    cleanup(localbuf);
    return (int)result;
}
