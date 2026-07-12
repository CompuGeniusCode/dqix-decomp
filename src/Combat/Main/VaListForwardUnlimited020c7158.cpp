#include <globaldefs.h>

typedef char* va_list;

extern "C" int func_020c7198(int a, int b, int c, va_list ap);

// USA: func_020c7158
ARM int VaListForwardUnlimited020c7158(int a, int b, va_list ap) {
    return func_020c7198(a, 0x7fffffff, b, ap);
}
