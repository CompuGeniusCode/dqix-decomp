#include <globaldefs.h>
extern "C" int Disp(void*, int);
extern "C" void* g1(void);
extern "C" int g2(void*);
extern "C" int h2(int, int);
struct D { char pad[8]; unsigned char* ptr; };
extern D dataX;

extern "C" int fswap(void* param) {
    if (!Disp(param, 4)) return 0;
    char* battle = (char*)g1();
    char* p = battle + 0x26c;
    void* state = g1();
    if (g2(state)) {
        int* aPtr = (int*)(p + 0x5d00);
        unsigned char* ptr = dataX.ptr;
        int a = *aPtr;
        int b = *(int*)(ptr + 0x18);
        if (h2(b, a)) {
        }
    }
    return 0;
}
