#include <globaldefs.h>

extern "C" void func_ov003_02159100(void*);

// USA: func_ov017_021babe0
ARM void CallField1cPtrB_021babe0(void* obj) {
    void* p = *(void**)((char*)obj + 0x1c);
    if (p) func_ov003_02159100(p);
}
