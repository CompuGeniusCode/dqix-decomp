#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void func_02094ab0(void);

int GetGlobalField0x1c020421a0(void);
void ReinitController02043204(char* obj);
int GetGlobal02109400(void);
int GetFieldIfFlag4(char* obj);
void SetField0x23cTrue(void* obj);

// USA: func_020d9ab0
ARM void InitBattleAndControllerState(void* param) {
    BattleStruct* bs = GetBattleStruct();
    ReinitController02043204((char*)GetGlobalField0x1c020421a0());
    GetGlobal02109400();
    func_02094ab0();
    SetField0x23cTrue((void*)GetFieldIfFlag4((char*)bs));
    *((unsigned char*)param + 1) = 1;
}
