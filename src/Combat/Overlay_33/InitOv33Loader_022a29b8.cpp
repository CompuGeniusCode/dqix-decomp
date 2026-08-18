#include <globaldefs.h>

#pragma define_section initcode ".init" RX

struct Obj022a296c;
struct Obj022a2998;
extern "C" void _Z26InitField0202f808_022a296cP11Obj022a296c(struct Obj022a296c*);
extern "C" void _Z26InitField0202f808_022a2998P11Obj022a2998(struct Obj022a2998*);
extern "C" void func_0200efd0(void*, void*, void*);

extern int data_ov033_022a2a2c;
extern int data_ov033_022a2a20;

// USA: func_ov033_022a29b8
extern "C" __declspec(initcode) ARM void func_ov033_022a29b8(void) {
    _Z26InitField0202f808_022a296cP11Obj022a296c((struct Obj022a296c*)&data_ov033_022a2a2c);
    func_0200efd0(&data_ov033_022a2a2c,
                  (void*)_Z26InitField0202f808_022a2998P11Obj022a2998,
                  &data_ov033_022a2a20);
}
