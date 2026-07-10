#include <globaldefs.h>

extern "C" int func_0201e1d0(int, int, int, int);

// USA: func_0201e2b4
ARM void SwapArgsAndCall0201e2b4(int a, int b, int c, int d) {
    func_0201e1d0(c, d, a, b);
}
