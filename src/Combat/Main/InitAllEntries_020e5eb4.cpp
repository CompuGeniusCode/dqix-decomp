#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern "C" void _Z22InitAllEntries02058704P11Obj02058704(void* obj);
extern "C" void _Z23RunAndReturnArg0205873cPv(void* obj);
extern "C" void func_0200efd0(int c, int b, void* node);

extern void* data_021079ec;
extern void* data_021079e0;

// USA: func_020e5eb4
extern "C" __declspec(initcode) ARM void func_020e5eb4(void) {
    _Z22InitAllEntries02058704P11Obj02058704(&data_021079ec);
    func_0200efd0((int)&data_021079ec, (int)_Z23RunAndReturnArg0205873cPv, &data_021079e0);
}
