#include <globaldefs.h>

extern "C" void* func_0207ecac(void* p);

// USA: func_02037528
ARM void* CallFunc0207ecacOnField0x8(void* obj) {
    void* p = *(void**)((char*)obj + 8);
    if (p == NULL) return p;
    return func_0207ecac(p);
}
