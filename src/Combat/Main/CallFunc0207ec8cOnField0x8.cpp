#include <globaldefs.h>

extern "C" void* func_0207ec8c(void* p);

// USA: func_02037540
ARM void* CallFunc0207ec8cOnField0x8(void* obj) {
    void* p = *(void**)((char*)obj + 8);
    if (p == NULL) return p;
    return func_0207ec8c(p);
}
