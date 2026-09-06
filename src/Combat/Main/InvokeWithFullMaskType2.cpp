#include <globaldefs.h>

extern "C" int func_020d5d34(int, int, int, int, int);

// USA: func_020d68b4
ARM int InvokeWithFullMaskType2(int a, int b) {
    return func_020d5d34(a, b, 0xffff, 2, 1);
}
