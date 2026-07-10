#include <globaldefs.h>

extern "C" int func_020a0db8(void* a, void* b, int c, int d);

// USA: func_0202ee58
ARM void CallFunc020a0db8AtField0x194AndClearFlag2(char* obj, int a, int b) {
    func_020a0db8(obj + 0x194, obj + 0x10, a, b);
    *(int*)(obj + 0x168) &= ~0x2;
}
