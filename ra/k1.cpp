#include <globaldefs.h>
extern "C" int f(int);
extern "C" void sink(int);
/* two COMPUTED values: swap def order -> registers swap (earlier = LOWER) */
extern "C" int k1(int* p) { int a=p[1]*3; int b=p[2]*5; sink(0); sink(a); sink(b); sink(a); sink(b); return 0; }
extern "C" int k2(int* p) { int b=p[2]*5; int a=p[1]*3; sink(0); sink(a); sink(b); sink(a); sink(b); return 0; }
/* two CALL values: swap def order -> registers swap (earlier = HIGHER) */
extern "C" int k3(void)  { int a=f(1); int b=f(2); sink(0); sink(a); sink(b); sink(a); sink(b); return 0; }
extern "C" int k4(void)  { int b=f(2); int a=f(1); sink(0); sink(a); sink(b); sink(a); sink(b); return 0; }
