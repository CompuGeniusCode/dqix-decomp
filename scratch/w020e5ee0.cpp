#include <globaldefs.h>

void EmptyDestructor0205ec2c(void* obj);
void EmptyDestructor0205ec30(void* obj);
extern "C" ARM void func_0200efd0(int c, int b, void* node);

extern int data_02108760;
extern int data_02108754;

#pragma define_section initcode ".init" RX
extern "C" __declspec(initcode) ARM void func_020e5ee0(void) {
    EmptyDestructor0205ec2c(&data_02108760);
    func_0200efd0((int)&data_02108760, (int)EmptyDestructor0205ec30, &data_02108754);
}
