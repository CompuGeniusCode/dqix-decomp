#include <globaldefs.h>
int f(int);
void sink(int);

int h1(short* p) {
    int A = f(1);
    int B = p[3]*6;
    sink(0); sink(A); sink(B); sink(A+B);
    return 0;
}
int h2(short* p) {
    int A = f(1);
    int B = p[3] * 6;
    sink(0); sink(A); sink(B); sink(A+B);
    return 0;
}
int h3(short* p) {
    int A = f(1);
    short t = p[3];
    int B; { B = t * 6; }
    sink(0); sink(A); sink(B); sink(A+B);
    return 0;
}
int h4(short* p, int q) {
    int A = f(1);
    int B = q ? p[3]*6 : p[4]*6;
    sink(0); sink(A); sink(B); sink(A+B);
    return 0;
}
