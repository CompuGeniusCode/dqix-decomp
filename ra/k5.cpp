#include <globaldefs.h>
extern "C" void sink(int);
extern "C" void* getA(void); extern "C" void* getB(void);
extern "C" int k5(short* p, short* q) { int a=p[3]*6; int b=q[7]*6; sink(0); sink(a); sink(b); sink(a+b); return 0; }
extern "C" int k6(short* p, short* q) { int b=q[7]*6; int a=p[3]*6; sink(0); sink(a); sink(b); sink(a+b); return 0; }
