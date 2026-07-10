#include <globaldefs.h>

extern "C" int func_020c7950(void* t);

// USA: func_020c7be8
ARM int ClearAndDispatch(void** slot) {
    void* t = *slot;
    *slot = NULL;
    *(int*)((char*)t + 0xb0) = 0;
    return func_020c7950(t);
}
