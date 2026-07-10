#include <globaldefs.h>

extern "C" void func_0207ea8c(void* p);
extern "C" void func_0207eae0(void* p);

// USA: func_020356f0
ARM void DispatchByFlag42_020356f0(unsigned char* obj) {
    void* p;
    if ((*(int*)(obj + 0x6c) & 8) == 0) return;
    p = *(void**)(obj + 8);
    if (p == NULL) return;
    if (obj[0x42] == 0) {
        func_0207ea8c(p);
    } else {
        func_0207eae0(p);
    }
}
