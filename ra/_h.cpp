#include <globaldefs.h>
extern "C" int f(int);
extern "C" void sink(int);
extern "C" int cond(int);
extern "C" int th(int* p, int q) {
    int A = f(1);
    int B = p[3] * 6;
    sink(A&0xff);
    if (cond(6)) { sink(A+B); }
    sink(B);
    if (cond(1)) { f(7); sink(B); } else { f(8); sink(A&0xff); }
    if (!cond(8)) { sink(B); f(6); } else { sink(A+B); }
    sink(A); sink(B);
    return 0;
}
