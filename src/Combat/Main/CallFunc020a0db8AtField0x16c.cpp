#include <globaldefs.h>

extern "C" int func_020a0db8(void* a, void* b, int c, int d);

// USA: func_0202ee38
ARM int CallFunc020a0db8AtField0x16c(char* obj, int a, int b) {
    return func_020a0db8(obj + 0x16c, obj + 0x4, a, b);
}
