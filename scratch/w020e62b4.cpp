#include <globaldefs.h>

struct Struct0208e9f4;
struct Struct0208e9f4* InitAndReturnSelf0208f4bc(struct Struct0208e9f4* p);
void* InitAndReturnSelf0208f4d0(void* obj);
extern "C" ARM void func_0200efd0(int c, int b, void* node);

extern struct Struct0208e9f4 data_02109020;
extern int data_02109014;

#pragma define_section initcode ".init" RX
extern "C" __declspec(initcode) ARM void func_020e62b4(void) {
    InitAndReturnSelf0208f4bc(&data_02109020);
    func_0200efd0((int)&data_02109020, (int)InitAndReturnSelf0208f4d0, &data_02109014);
}
