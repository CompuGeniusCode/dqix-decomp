#include <globaldefs.h>

extern "C" void* func_0207ecd4(void* p);

// USA: func_02055624
ARM void* Field0x1cCall0207ecd4OrNull(void* obj) {
    void* x = *(void**)((char*)obj + 0x1c);
    if (x == NULL) return x;
    return func_0207ecd4(x);
}
