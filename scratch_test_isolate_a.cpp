#include <globaldefs.h>
extern "C" int Disp(void*, int);
extern "C" void* g1(void);
extern "C" int g2(void*);
extern "C" void h(void*, int);
extern "C" int h2(int, int);

extern "C" int fisoA(void* param) {
    if (!Disp(param, 4)) return 0;
    char* battle = (char*)g1();
    char* p = battle + 0x26c;
    void* state = g1();
    if (g2(state)) {
        int* aPtr = (int*)(p + 0x5d00);
        int a = *aPtr;
        if (h2(a, 5)) {
            h(param, 1);
        }
    }
    h(param, 3);
    return 0;
}
