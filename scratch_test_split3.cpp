#include <globaldefs.h>

extern "C" void* g1(void);
extern "C" int g2(void*);

extern "C" int f8(char* battle) {
    char* p = battle + 0x26c;
    void* state = g1();
    if (g2(state)) {
        return *(int*)(p + 0x5d00);
    }
    return 0;
}
