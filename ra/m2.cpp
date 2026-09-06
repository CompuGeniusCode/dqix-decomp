#include <globaldefs.h>
extern "C" int f1(void*,int);
extern "C" void* f4(void*,int);
extern "C" void g(int,int,int,int);
extern "C" int tm(void* obj) {
    int code = f1(obj, 0x5b);
    int mult = f1(obj, 6);
    g(mult+code,0,1,0);
    g(mult+code,0,3,0);
    return 0;
}
