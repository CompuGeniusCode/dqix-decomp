#include <globaldefs.h>

extern "C" int func_020cc310(void*);
extern "C" void func_020cc21c(void*);

// USA: func_020afce4
ARM int TryApplyIfValid(void* p) {
    if (func_020cc310(p) == 0) return 0;
    func_020cc21c(p);
    return 1;
}
