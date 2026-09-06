#include <globaldefs.h>

extern "C" void func_0209c5e8(void*);
extern "C" void func_0209c2e0(void*, int, int);
extern void* data_02109bf4;

// USA: func_ov001_021636a8
ARM int InitAndSetActorValue_021636a8(void) {
    func_0209c5e8(&data_02109bf4);
    func_0209c2e0(&data_02109bf4, 0x7f, 0);
    return 1;
}
