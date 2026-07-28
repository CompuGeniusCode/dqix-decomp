#include <globaldefs.h>
extern "C" int f(int);
extern "C" void sink(int);
extern "C" int g1(int a, int b) {   /* two params, both live across calls */
    int c = f(1);
    int d = a + b;                  /* computed */
    sink(0);
    sink(a); sink(b); sink(c); sink(d);
    return 0;
}
extern "C" int g2(int* p, int q) {
    int c = f(1);
    sink(0);
    sink(q); sink(c); sink(p[3]);
    return 0;
}
