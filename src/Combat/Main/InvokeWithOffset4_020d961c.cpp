#include <globaldefs.h>

extern "C" int func_020d91a8(void* a, void* b);

// USA: func_020d961c
ARM int InvokeWithOffset4_020d961c(char* p) {
    return func_020d91a8(p, p + 4);
}
