#include <globaldefs.h>

extern "C" int func_020bdac0(void* p);

// USA: func_0203aa64
ARM int GetFromField00203aa64(void* obj) {
    void* p = *(void**)obj;
    if (p == NULL) return 0;
    return func_020bdac0(p);
}
