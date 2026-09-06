#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" int func_ov001_0215ab20(int);
extern "C" void _Z23SetLinkIfType3_021d6148P12Node021d6148j(void* node, float v);

struct Entry0215ff10 { char pad[0x74]; int a, b, c; };

// USA: func_ov001_0215ff10
extern "C" ARM int func_ov001_0215ff10(char* obj, int count) {
    char* orig = obj;
    obj = obj + 8;
    int idx = func_ov017_021d60f4(orig);
    Entry0215ff10* e = (Entry0215ff10*)func_ov001_0215ab20(idx);
    if (e == NULL) return 0;
    float v1 = (float)e->a / 4096.0f;
    float v2 = (float)e->b / 4096.0f;
    float v3 = (float)e->c / 4096.0f;
    if (count >= 2) {
        _Z23SetLinkIfType3_021d6148P12Node021d6148j(obj, v1);
        obj += 8;
    }
    if (count >= 3) {
        _Z23SetLinkIfType3_021d6148P12Node021d6148j(obj, v2);
        obj += 8;
    }
    if (count >= 4) {
        _Z23SetLinkIfType3_021d6148P12Node021d6148j(obj, v3);
    }
    return 1;
}
