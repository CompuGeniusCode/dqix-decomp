#include <globaldefs.h>
extern "C" int f(int);
extern "C" void h(int,int);
extern "C" void h1(int);
extern "C" int tf(int p) {
    int a = f(1);
    int b = f(2);
    h(a,b);
    h(a,b);
    h(a,b);
    return 0;
}
