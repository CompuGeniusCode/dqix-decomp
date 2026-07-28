#include <globaldefs.h>
extern "C" int Disp(void*, int);
extern "C" void* g1(void);
extern "C" int g2(void*);
extern "C" int h2(void*, int);

extern "C" int fptrtype(void* param) {
    if (!Disp(param, 4)) return 0;
    char* battle = (char*)g1();
    char* p = battle + 0x26c;
    void* state = g1();
    if (g2(state)) {
        void** aPtr = (void**)(p + 0x5d00);
        void* a = *aPtr;
        if (h2(a, 5)) {
        }
    }
    return 0;
}
