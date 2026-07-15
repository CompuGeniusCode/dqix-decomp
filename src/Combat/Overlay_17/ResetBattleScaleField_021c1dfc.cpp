#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern int GetGlobalField0x1c020421a0();
extern unsigned int GetBattleScaleCount(struct BattleStruct* battleStruct);
extern void Forward0204359c(void* obj, int count);
extern "C" void func_020439b0(void* obj, int flag);

// USA: func_ov017_021c1dfc
ARM void ResetBattleScaleField_021c1dfc(void) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    void* obj = (void*)GetGlobalField0x1c020421a0();
    int count = GetBattleScaleCount(battleStruct);
    Forward0204359c(obj, count);
    func_020439b0(obj, 0);
}
