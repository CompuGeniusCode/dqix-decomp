#include <globaldefs.h>
#pragma define_section initcode ".init" RX

struct func_0200efd0 {
    struct func_0200efd0* next;
    int b;
    int c;
};

extern "C" void* _Z31InitObjectWithCallbacks02028c8cPv(void* obj);
extern "C" void* _Z23InitObjectArray02028d2cPv(void* obj);
extern "C" ARM void func_0200efd0(int c, int b, struct func_0200efd0* node);

extern void* data_020fdd44;
extern void* data_020fdd38;

// USA: func_020e5afc
extern "C" __declspec(initcode) ARM void func_020e5afc(void) {
    _Z31InitObjectWithCallbacks02028c8cPv(&data_020fdd44);
    func_0200efd0((int)&data_020fdd44, (int)_Z23InitObjectArray02028d2cPv, (struct func_0200efd0*)&data_020fdd38);
}
