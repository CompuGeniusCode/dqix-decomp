#include <globaldefs.h>

extern "C" void func_0203c2c0(void* obj);
extern "C" void func_0203bd24(void* obj);

// USA: func_0203c73c
ARM char* InitCombatObject0203c73c(char* obj) {
    func_0203c2c0(obj + 0x10);
    func_0203bd24(obj);
    return obj;
}
