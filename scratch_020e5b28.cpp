#include <globaldefs.h>

extern "C" void func_0200efd0(void* obj, void* func, void* node);
ARM void* InitReturnSelf0202c794(void* obj);
ARM void* InitReturnSelf0202c7a8(void* obj);
ARM void* ResetBattleArray0202c7bc(void* obj);
ARM void* ReleaseBattleArray0202c814(void* obj);

extern int data_020fefec;
extern int data_020fefe0;
extern int data_02100044;
extern int data_020fefd4;

// USA: func_020e5b28
ARM void InitBattleContexts_020e5b28(void) {
    InitReturnSelf0202c794(&data_020fefec);
    func_0200efd0(&data_020fefec, (void*)InitReturnSelf0202c7a8, &data_020fefe0);
    ResetBattleArray0202c7bc(&data_02100044);
    func_0200efd0(&data_02100044, (void*)ReleaseBattleArray0202c814, &data_020fefd4);
}
