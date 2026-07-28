#include <globaldefs.h>
extern "C" int f(int);
extern "C" void sink(int);
extern "C" int g3(int a, int* p) {
    int c = f(1);        /* call */
    int d = p[7];        /* computed */
    sink(0);
    sink(a); sink(c); sink(d); sink(a); sink(c); sink(d);
    return 0;
}
extern "C" int g4(int a, int* p) {
    int d = p[7];        /* computed first */
    int c = f(1);        /* call second */
    sink(0);
    sink(a); sink(c); sink(d); sink(a); sink(c); sink(d);
    return 0;
}
