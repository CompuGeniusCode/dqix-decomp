#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern "C" ARM char* _Z22ClearAndReturn0207c244Pc(char* obj);
extern "C" ARM char* _Z32ClearRegionAndReturnSelf020269d0Pc(char* obj);

extern "C" void __register_global_object(int c, int b, void* node);

extern char data_02108e90;
extern int data_02108e84;

// USA: func_020e6234
extern "C" __declspec(initcode) ARM void __sinit_020e6234(void) {
    _Z22ClearAndReturn0207c244Pc(&data_02108e90);
    __register_global_object((int)&data_02108e90, (int)_Z32ClearRegionAndReturnSelf020269d0Pc, &data_02108e84);
}
