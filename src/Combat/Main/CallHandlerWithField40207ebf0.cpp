#include <globaldefs.h>

int GetField4Ptr0207e224(void*);
extern "C" void func_020b2ce0(void* a, int b);

// USA: func_0207ebf0
ARM void CallHandlerWithField40207ebf0(void* a, void* entry) {
    if (entry == NULL) return;
    if (GetField4Ptr0207e224(entry) == 0) return;
    func_020b2ce0(a, GetField4Ptr0207e224(entry));
}
