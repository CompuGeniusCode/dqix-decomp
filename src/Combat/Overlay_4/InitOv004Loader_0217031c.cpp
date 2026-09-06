#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern "C" void* _Z25DoResetInitOrder_021633e4Pv(void* obj);
extern "C" void* _Z25DoInitResetOrder_02163408Pv(void* obj);
extern "C" void __register_global_object(void*, void*, void*);

extern int data_ov004_021708c8;
extern int data_ov004_0217082c;

// USA: func_ov004_0217031c  (semantic: InitOv004Loader_0217031c)
extern "C" __declspec(initcode) ARM void __sinit_ov004_0217031c(void) {
    _Z25DoResetInitOrder_021633e4Pv(&data_ov004_021708c8);
    __register_global_object(&data_ov004_021708c8, (void*)_Z25DoInitResetOrder_02163408Pv, &data_ov004_0217082c);
}
