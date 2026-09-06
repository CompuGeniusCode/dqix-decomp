#include <globaldefs.h>
extern "C" int f(int);
extern "C" void sink(int);
extern "C" int tf(int* p, int c) {
    int v0 = f(0);
    if (v0 < 0) return 0;
    int v1 = p[2];
    if (!f(9)) { sink(8); goto end; }
    {
    int v2 = p[3];
        sink(v0);
        sink(v1);
        sink(v2);
    }
end:
    return 0;
}
