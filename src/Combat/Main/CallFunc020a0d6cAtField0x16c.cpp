#include <globaldefs.h>

extern "C" int func_020a0d6c(void* a, void* b, int c, int d, int e, int f);

// USA: func_0202ed7c
ARM int CallFunc020a0d6cAtField0x16c(char* obj, int a, int b, int c, int d) {
    return func_020a0d6c(obj + 0x16c, obj + 0x4, a, b, c, d);
}
