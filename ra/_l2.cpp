#include <globaldefs.h>
extern "C" int f(int);
extern "C" void sink(int);
extern "C" int tf(int* p) {
    int v0 = p[1];
    int v1 = p[2];
    int v2 = p[3];
    int v3 = p[4];
    sink(0);
    sink(v0);
    sink(v1);
    sink(v2);
    sink(v3);

    return 0;
}
