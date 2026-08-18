#include <globaldefs.h>

#pragma define_section initcode ".init" RX

struct _Z20InitDefaults0208e9f4P14Struct0208e9f4;
extern "C" ARM void* _Z25InitAndReturnSelf0208f4bcP14Struct0208e9f4(struct _Z20InitDefaults0208e9f4P14Struct0208e9f4* obj);
extern "C" ARM void* _Z25InitAndReturnSelf0208f4d0Pv(void* obj);

extern "C" void func_0200efd0(int c, int b, void* node);

extern _Z20InitDefaults0208e9f4P14Struct0208e9f4 data_02109020;
extern int data_02109014;

// USA: func_020e62b4
extern "C" __declspec(initcode) ARM void func_020e62b4(void) {
    _Z25InitAndReturnSelf0208f4bcP14Struct0208e9f4(&data_02109020);
    func_0200efd0((int)&data_02109020, (int)_Z25InitAndReturnSelf0208f4d0Pv, &data_02109014);
}
