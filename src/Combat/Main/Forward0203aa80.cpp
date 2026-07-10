#include <globaldefs.h>

extern "C" void func_020bdb0c(void* a, int b);

// USA: func_0203aa80
ARM void Forward0203aa80(void* obj, int arg2) {
    void* p = *(void**)obj;
    if (p == NULL) return;
    func_020bdb0c(p, arg2);
}
