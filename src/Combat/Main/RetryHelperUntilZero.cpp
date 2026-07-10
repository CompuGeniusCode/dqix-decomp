#include <globaldefs.h>

extern "C" int func_020cae94(int a, int b, int c);

// USA: func_020ce870
ARM void RetryHelperUntilZero(int arg) {
    while (func_020cae94(8, arg, 0) != 0) {}
}
