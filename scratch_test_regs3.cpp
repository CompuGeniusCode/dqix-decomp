#include <globaldefs.h>
extern "C" void* g1(void);
extern "C" int g2(void*);
extern "C" void h(void*, int);
extern "C" int h2(void*, int);

extern "C" int frr3(void* param) {
    char* battle = (char*)g1();
    char* p = battle + 0x26c;
    void* state = g1();
    if (g2(state)) {
        int x = *(int*)(p + 0x5d00);
        if (h2((void*)x, 1)) {
            int y = *(int*)(battle + 0x300);
            h((void*)y, 2);
        }
    }
    h(param, 3);
    return 0;
}
