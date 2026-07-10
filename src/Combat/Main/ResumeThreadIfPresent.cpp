#include <globaldefs.h>

extern "C" void* func_020c9100(void* p);

// USA: func_020c783c
ARM void* ResumeThreadIfPresent(void* obj) {
    void* p = *(void**)((char*)obj + 0xb0);
    if (p != NULL) {
        p = func_020c9100(p);
    }
    return p;
}
