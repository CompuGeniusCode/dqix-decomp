#include <globaldefs.h>

extern int data_ov017_021d8498;
extern "C" void func_ov017_021d451c(void* a, void* b);
extern "C" void func_ov017_021d45e0(void* a, void* b);

struct Bits021c912c { unsigned char sub2 : 2; unsigned char rest : 6; };
struct Obj021c912c { unsigned char pad[4]; Bits021c912c field4; };

// USA: func_ov017_021c912c
ARM void DispatchBitfieldHandler_021c912c(void* unused, Obj021c912c* obj) {
    void* base = &data_ov017_021d8498;
    unsigned int sub = obj->field4.sub2;
    if (sub == 0) {
        func_ov017_021d451c(base, (char*)obj + 6);
        return;
    }
    if (sub != 1) return;
    func_ov017_021d45e0(base, (char*)obj + 6);
}
