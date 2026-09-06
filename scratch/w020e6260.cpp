#include <globaldefs.h>

struct Init0207d7c0;
struct Init0207d7c0* ConstructStructArray0207ddf0(struct Init0207d7c0* arr);
struct Init0207d7c0* ConstructStructArray0207de1c(struct Init0207d7c0* arr);
extern "C" ARM void func_0200efd0(int c, int b, void* node);

extern struct Init0207d7c0 data_02108ea8;
extern int data_02108e9c;

#pragma define_section initcode ".init" RX
extern "C" __declspec(initcode) ARM void func_020e6260(void) {
    ConstructStructArray0207ddf0(&data_02108ea8);
    func_0200efd0((int)&data_02108ea8, (int)ConstructStructArray0207de1c, &data_02108e9c);
}
