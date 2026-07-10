#include <globaldefs.h>

extern "C" void* func_0207ecf8(void* p);

// USA: func_0205560c
ARM void* Field0x1cCall0207ecf8OrNull(void* obj) {
    void* x = *(void**)((char*)obj + 0x1c);
    if (x == NULL) return x;
    return func_0207ecf8(x);
}
