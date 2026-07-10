#include <globaldefs.h>

extern "C" int func_020a0d6c(void* a, void* b, int c, int d, int e, int f);

// USA: func_0202edb4
ARM void CallFunc020a0d6cAtField0x194AndClearFlag2(char* obj, int a, int b, int c, int d) {
    func_020a0d6c(obj + 0x194, obj + 0x10, a, b, c, d);
    *(int*)(obj + 0x168) &= ~0x2;
}
