#include <globaldefs.h>

void* ClearFourRegions02079fc8(char* obj);
char* ClearFourRegions0207a014(char* obj);
extern "C" ARM void func_0200efd0(int c, int b, void* node);

extern char data_02108e10;
extern int data_02108e04;

#pragma define_section initcode ".init" RX
extern "C" __declspec(initcode) ARM void func_020e60f8(void) {
    ClearFourRegions02079fc8(&data_02108e10);
    func_0200efd0((int)&data_02108e10, (int)ClearFourRegions0207a014, &data_02108e04);
}
