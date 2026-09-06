#include <globaldefs.h>

typedef char* va_list;

int VaListForwardUnlimited020c7158(int a, int b, va_list ap);

// USA: func_020c7130
ARM int VariadicForward020c7130(int a, int b, ...) {
    va_list ap = (va_list)(((unsigned int)&b & ~3u) + 4);
    return VaListForwardUnlimited020c7158(a, b, ap);
}
