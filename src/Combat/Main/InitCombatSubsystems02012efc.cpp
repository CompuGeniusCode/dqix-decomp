#include <globaldefs.h>

extern "C" void func_02012de8(void);
extern "C" void func_020e123c(void);
extern "C" void func_0201229c(void*);
extern "C" void func_02012538(void*);

extern int data_02114e30;
extern int data_02114e54;

// USA: func_02012efc
ARM void InitCombatSubsystems02012efc(void) {
    func_02012de8();
    func_020e123c();
    func_0201229c(&data_02114e30);
    func_02012538(&data_02114e54);
}
