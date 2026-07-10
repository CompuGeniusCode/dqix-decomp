#include <globaldefs.h>

extern "C" void func_0202eab8(void* obj);
extern "C" void func_020a0d6c(void* a, void* b, int c, int d, int e, int f);

// USA: func_0202edf8
ARM void Call0202eab8AndApply020a0d6c(char* obj, int a, int b, int c, int d) {
    func_0202eab8(obj);
    func_020a0d6c(obj + 0x1bc, obj + 0x70, a, b, c, d);
}
