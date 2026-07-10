#include <globaldefs.h>

extern "C" void func_020bdb0c(void* a, int b);

// USA: func_0203aa44
ARM void CallField0xa00203aa44(void* obj) {
    void* p = *(void**)obj;
    if (p == NULL) return;
    func_020bdb0c(p, *(int*)((char*)obj + 0xa0));
}
