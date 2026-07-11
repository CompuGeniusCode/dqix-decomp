#include <globaldefs.h>
void InitBattleObject0203c2c0(char*);

void InitBattleContext0203bd24(char*);

// USA: func_0203c73c
ARM char* InitCombatObject0203c73c(char* obj) {
    InitBattleObject0203c2c0((char*)(obj + 0x10));
    InitBattleContext0203bd24((char*)obj);
    return obj;
}
