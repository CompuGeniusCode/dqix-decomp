#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetGlobalField0x1c020421a0(void);
void ReinitController02043204(char* obj);
int GetGlobal02109400(void);
extern "C" void func_02094ab0(void);
extern "C" void func_0203b110(void* p, int a, int b);
extern "C" void* func_ov017_0218b5b0(void);
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
void SetByteField0x253(void* obj);
extern "C" void func_ov017_021a9fa0(int self);

// USA: func_ov017_021a9f58
ARM void Something_021a9f58(int selfParam) {
    struct BattleStruct* battle = GetBattleStruct();
    ReinitController02043204((char*)(long)GetGlobalField0x1c020421a0());
    GetGlobal02109400();
    func_02094ab0();
    func_0203b110(func_ov017_0218b5b0(), 0, 0x14);
    SetByteField0x253(GetCombatantAtField0x397c(battle));
    func_ov017_021a9fa0(selfParam);
}
