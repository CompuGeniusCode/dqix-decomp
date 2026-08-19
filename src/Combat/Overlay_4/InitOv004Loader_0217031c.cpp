#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern "C" void* _Z25DoResetInitOrder_021633e4Pv(void* obj);
extern "C" void* _Z25DoInitResetOrder_02163408Pv(void* obj);
extern "C" void func_0200efd0(void*, void*, void*);

extern int data_ov004_021708c8;
extern int data_ov004_0217082c;

// USA: func_ov004_0217031c  (semantic: InitOv004Loader_0217031c)
extern "C" __declspec(initcode) ARM void func_ov004_0217031c(void) {
    _Z25DoResetInitOrder_021633e4Pv(&data_ov004_021708c8);
    func_0200efd0(&data_ov004_021708c8, (void*)_Z25DoInitResetOrder_02163408Pv, &data_ov004_0217082c);
}
