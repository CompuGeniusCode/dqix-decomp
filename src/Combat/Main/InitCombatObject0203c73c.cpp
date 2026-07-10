#include <globaldefs.h>

extern "C" void func_0203c2c0(void* obj);
void InitBattleContext0203bd24(char*);

// USA: func_0203c73c
ARM char* InitCombatObject0203c73c(char* obj) {
    func_0203c2c0(obj + 0x10);
    InitBattleContext0203bd24((char*)obj);
    return obj;
}
