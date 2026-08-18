#include <globaldefs.h>
#pragma define_section initcode ".init" RX

struct func_0200efd0 {
    struct func_0200efd0* next;
    int b;
    int c;
};

extern "C" char* _Z24InitCombatObject0203c73cPc(char* obj);
extern "C" char* _Z24InitBattleObject0203c75cPc(char* obj);
extern "C" ARM void func_0200efd0(int c, int b, struct func_0200efd0* node);

extern void* data_02105ab4;
extern void* data_02105248;

// USA: func_020e5c2c
extern "C" __declspec(initcode) ARM void func_020e5c2c(void) {
    _Z24InitCombatObject0203c73cPc((char*)&data_02105ab4);
    func_0200efd0((int)&data_02105ab4, (int)(void*)_Z24InitBattleObject0203c75cPc, (struct func_0200efd0*)&data_02105248);
}
