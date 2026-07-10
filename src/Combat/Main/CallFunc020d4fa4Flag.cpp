#include <globaldefs.h>

extern "C" int func_020d4fa4(int, int, int, int);

// USA: func_020d4f8c
ARM int CallFunc020d4fa4Flag(int a, int b, int c, int d) {
    int v = 1;
    if (d == 0) v |= 2;
    return func_020d4fa4(a, b, c, v);
}
