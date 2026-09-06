#include <globaldefs.h>
extern "C" int f1(void*,int);
extern "C" void* f4(void*,int);
extern "C" void* f5(void*,int);
extern "C" void g(int,int,int,int);
extern "C" int tm(void* obj) {
    int A = f1(obj, 1);
    void* node = f4(obj, 0x5b);
    int B = ((int*)node)[2];
    int C = f1(obj, 3);
    f5(obj,C);
    g(A+B,0,1,0);
    g(A+B,0,3,0);
    f5(obj,7);
    return 0;
}
