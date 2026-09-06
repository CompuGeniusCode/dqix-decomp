#include <globaldefs.h>
extern "C" int Disp(void*, int);
extern "C" void* g1(void*, int);
extern "C" short* g2(void*, int);
extern "C" void* g3(void*, int);

extern "C" int fcr(void* obj) {
    int code = Disp(obj, 0x5b);
    if (code < 0) return 0;
    void* node = g1(obj, 0x5b);
    short field5c = *((short*)node + 0x2e);
    int mult = field5c * 6;
    void* entry = g3(obj, code & 0xff);
    (void)entry; (void)mult; (void)code;
    return code + mult;
}
