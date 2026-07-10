#include <globaldefs.h>

extern "C" void func_020dd8b4(int, int, int, int);
extern "C" void func_020dd9b4(int, int, int, int);

// USA: func_020ddaf4
ARM void Setup020ddaf4(int a, int b, int c, int d, int e, int f) {
    func_020dd8b4(a, b, c, 0);
    func_020dd9b4(a, d, e, f);
}
