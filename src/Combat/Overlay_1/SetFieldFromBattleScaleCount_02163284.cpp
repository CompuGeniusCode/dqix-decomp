#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

unsigned int GetBattleScaleCount(struct BattleStruct* battleStruct);
extern "C" void func_ov017_021d6134(void*, unsigned int);

// USA: func_ov001_02163284
ARM int SetFieldFromBattleScaleCount_02163284(void* obj) {
    unsigned int v = GetBattleScaleCount(GetBattleStruct());
    func_ov017_021d6134(obj, v);
    return 1;
}
