#include <globaldefs.h>
extern "C" void* g1(void);
extern "C" int g2(void*);
extern "C" void h(void*, int);

extern "C" int frr2(void* param) {
    void* a = g1();
    char* b = (char*)a + 0x26c;
    void* state = g1();
    if (g2(state)) {
        int x = *(int*)(b + 0x5d00);
        h((void*)x, 1);
    }
    h(param, 2);
    return 0;
}
