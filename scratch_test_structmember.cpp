#include <globaldefs.h>
extern "C" int Disp(void*, int);
extern "C" void* g1(void);
extern "C" int g2(void*);
extern "C" int h2(int, int);
struct Big5d00 { char pad[0x5d00]; int val; };

extern "C" int fstruct(void* param) {
    if (!Disp(param, 4)) return 0;
    char* battle = (char*)g1();
    struct Big5d00* p = (struct Big5d00*)(battle + 0x26c);
    void* state = g1();
    if (g2(state)) {
        int a = p->val;
        if (h2(a, 5)) {
        }
    }
    return 0;
}
