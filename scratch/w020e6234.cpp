#include <globaldefs.h>

char* ClearAndReturn0207c244(char* obj);
char* ClearRegionAndReturnSelf020269d0(char* obj);
extern "C" ARM void func_0200efd0(int c, int b, void* node);

extern char data_02108e90;
extern int data_02108e84;

#pragma define_section initcode ".init" RX
extern "C" __declspec(initcode) ARM void func_020e6234(void) {
    ClearAndReturn0207c244(&data_02108e90);
    func_0200efd0((int)&data_02108e90, (int)ClearRegionAndReturnSelf020269d0, &data_02108e84);
}
