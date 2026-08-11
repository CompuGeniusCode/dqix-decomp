#include <globaldefs.h>

int GetGlobalField0x1c020421a0();
extern "C" void func_0204500c(void* field, void* buf, int p2, int p3);
extern "C" void func_02042b98(void* self, int arg1, int arg2, int arg3, int arg4);

struct Param021e5e1c { char pad[8]; void* field8; };

// USA: func_ov025_021e5e1c  (semantic: InitGlobalFieldsAndFlags_021e5e1c)
extern "C" ARM void func_ov025_021e5e1c(struct Param021e5e1c* p) {
    int base = GetGlobalField0x1c020421a0();
    void* field8 = p->field8;
    func_0204500c((void*)base, field8, 0, 0xe3);
    *(unsigned char*)(base + 0x1000 + 0x9b1) = 0;
    func_02042b98((void*)base, 2, 0x92, 0xfc, 0x4a);
    *(unsigned char*)(base + 0x1000 + 0x9b2) = 0;
    *(int*)(base + 0x998) = 1;
}
