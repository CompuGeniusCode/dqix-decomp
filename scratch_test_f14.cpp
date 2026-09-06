#include <globaldefs.h>
extern "C" void* g1(void);
extern "C" int g2(void*);
extern "C" void* GBS(void);
struct D { char pad[8]; unsigned char* ptr; };
extern D dataX;
extern "C" int g4(int, int);
extern "C" void g5(void*, int);

extern "C" int f14(void* obj) {
    void* battle = GBS();
    char* p = (char*)battle + 0x26c;
    void* state = g1();
    if (g2(state)) {
        if (g4(*(int*)(p + 0x5d00), *(int*)(dataX.ptr + 0x18))) {
        }
    }
    g5(obj, 1);
    return 0;
}
