#include <globaldefs.h>

extern "C" int func_0207e224(void* p);
extern "C" void func_020b2ce0(void* a, int b);

// USA: func_0207ebf0
ARM void CallHandlerWithField40207ebf0(void* a, void* entry) {
    if (entry == NULL) return;
    if (func_0207e224(entry) == 0) return;
    func_020b2ce0(a, func_0207e224(entry));
}
