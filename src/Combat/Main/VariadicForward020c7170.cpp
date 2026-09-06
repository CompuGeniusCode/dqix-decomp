#include <globaldefs.h>

typedef char* va_list;

extern "C" int func_020c7198(int a, int b, int c, va_list ap);

// USA: func_020c7170
ARM int VariadicForward020c7170(int a, int b, int c, ...) {
    va_list ap = (va_list)(((unsigned int)&c & ~3u) + 4);
    return func_020c7198(a, b, c, ap);
}
