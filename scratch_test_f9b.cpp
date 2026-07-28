#include <globaldefs.h>
extern "C" int g3(void*);
extern "C" int g4(void*);
extern "C" int f9b(char* p) {
    void* q = (void*)(p + 0x5d00);
    if (g3(q)) return g4(q);
    return 0;
}
