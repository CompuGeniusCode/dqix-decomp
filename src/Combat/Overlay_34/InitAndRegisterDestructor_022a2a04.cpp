#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern "C" void func_ov034_022a29b8(void*);
extern "C" void func_ov034_022a29e4(void*);
extern "C" int func_0200efd0(void*, void*, void*);

extern int data_ov034_022a2a6c;
extern int data_ov034_022a2a60;

// USA: func_ov034_022a2a04
extern "C" __declspec(initcode) ARM void func_ov034_022a2a04(void) {
    func_ov034_022a29b8(&data_ov034_022a2a6c);
    func_0200efd0(&data_ov034_022a2a6c, (void*)func_ov034_022a29e4, &data_ov034_022a2a60);
}
