#include <globaldefs.h>

void* SetGlobalContext02110370(void*);
extern "C" void* _Z24CallFunc020bc548OnField0Pv(void* obj, int arg2);

// USA: func_0203ac10
ARM void SetContextAndDispatch0203ac10(void* obj, void* a, int b) {
    char* p = (char*)obj;
    if (*(void**)p == NULL) return;
    SetGlobalContext02110370(p + 0x4);
    _Z24CallFunc020bc548OnField0Pv(a, b);
}
