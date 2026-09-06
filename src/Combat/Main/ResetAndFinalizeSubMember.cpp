#include <globaldefs.h>

extern "C" void func_0200f3a4(void*);
int ForwardFirstWord020998ac(int*);

// USA: func_02012224
ARM char* ResetAndFinalizeSubMember(char* obj) {
    func_0200f3a4(obj);
    ForwardFirstWord020998ac((int*)(obj + 0x468));
    return obj;
}
