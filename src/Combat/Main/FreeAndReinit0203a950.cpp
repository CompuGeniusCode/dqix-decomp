#include <globaldefs.h>

extern "C" void func_020bd984(void*);
void InitObjectFields0203a914(void*);

// USA: func_0203a950
ARM void FreeAndReinit0203a950(void* obj) {
    void* p = *(void**)obj;
    if (p != NULL) {
        func_020bd984(p);
    }
    InitObjectFields0203a914(obj);
}
