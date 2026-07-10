#include <globaldefs.h>

extern "C" void func_0200f3a4(void*);
extern "C" void func_020998ac(void*);

// USA: func_02012224
ARM char* ResetAndFinalizeSubMember(char* obj) {
    func_0200f3a4(obj);
    func_020998ac(obj + 0x468);
    return obj;
}
