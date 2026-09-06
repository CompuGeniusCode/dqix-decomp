#include <globaldefs.h>
#pragma define_section initcode ".init" RX

extern "C" void* _Z22InitReturnSelf0202c794Pv(void*);
extern "C" void* _Z22InitReturnSelf0202c7a8Pv(void*);
extern "C" void* _Z24ResetBattleArray0202c7bcPv(void*);
extern "C" void _Z26ReleaseBattleArray0202c814Pv(void*);
extern "C" void func_0200efd0(void*, void*, void*);

extern int data_020fefec;
extern int data_020fefe0;
extern int data_02100044;
extern int data_020fefd4;

// USA: func_020e5b28
extern "C" __declspec(initcode) ARM void func_020e5b28(void) {
    _Z22InitReturnSelf0202c794Pv(&data_020fefec);
    func_0200efd0(&data_020fefec, (void*)_Z22InitReturnSelf0202c7a8Pv, &data_020fefe0);
    _Z24ResetBattleArray0202c7bcPv(&data_02100044);
    func_0200efd0(&data_02100044, (void*)_Z26ReleaseBattleArray0202c814Pv, &data_020fefd4);
}
