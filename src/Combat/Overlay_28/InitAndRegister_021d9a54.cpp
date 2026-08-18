#include <globaldefs.h>

#pragma define_section initcode ".init" RX

struct Obj021d977c;
extern "C" void _Z30InitAllocatorAndReset_021d977cP11Obj021d977c(struct Obj021d977c* obj);
extern "C" void* func_ov028_021d979c(void* obj);
extern "C" void func_0200efd0(void* a, void* b, void* c);

extern int data_ov028_021d9b14;
extern int data_ov028_021d9ae0;

// USA: func_ov028_021d9a54  (semantic: InitAndRegister_021d9a54)
extern "C" __declspec(initcode) ARM void func_ov028_021d9a54(void) {
    _Z30InitAllocatorAndReset_021d977cP11Obj021d977c((struct Obj021d977c*)&data_ov028_021d9b14);
    func_0200efd0(&data_ov028_021d9b14, (void*)func_ov028_021d979c, &data_ov028_021d9ae0);
}
