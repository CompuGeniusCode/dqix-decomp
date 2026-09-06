#include <globaldefs.h>
#pragma define_section initcode ".init" RX

struct __register_global_object {
    struct __register_global_object* next;
    int b;
    int c;
};

extern "C" char* _Z24InitCombatObject0203c73cPc(char* obj);
extern "C" char* _Z24InitBattleObject0203c75cPc(char* obj);
extern "C" ARM void __register_global_object(int c, int b, struct __register_global_object* node);

extern void* data_02105ab4;
extern void* data_02105248;

// USA: func_020e5c2c
extern "C" __declspec(initcode) ARM void __sinit_020e5c2c(void) {
    _Z24InitCombatObject0203c73cPc((char*)&data_02105ab4);
    __register_global_object((int)&data_02105ab4, (int)(void*)_Z24InitBattleObject0203c75cPc, (struct __register_global_object*)&data_02105248);
}
