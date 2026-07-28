#include <globaldefs.h>
extern "C" int f1(void*,int);
extern "C" void* f4(void*,int);
extern "C" void* f5(void*,int);
extern "C" void g(int,int,int,int);
extern "C" int tm(void* obj) {
    unsigned int code = f1(obj, 0x5b);
    void* node = f4(obj, 0x5b);
    int mult = *(short*)((char*)node + 0x5c) * 6;
    void* entry = f5(obj, code & 0xff);
    g(mult+code,(int)entry,1,0);
    g(mult+code,0,3,0);
    return 0;
}
