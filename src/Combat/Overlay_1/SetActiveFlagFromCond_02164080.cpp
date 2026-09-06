#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" int func_ov017_021d60f4(void* obj);
void SetActiveFlag(struct BattleStruct* battleStruct, int active);

// USA: func_ov001_02164080  (semantic: SetActiveFlagFromCond_02164080)
extern "C" ARM int func_ov001_02164080(void* obj) {
    int cond = func_ov017_021d60f4(obj);
    struct BattleStruct* battleStruct = GetBattleStruct();
    if (cond != 0)
        SetActiveFlag(battleStruct, 0);
    else
        SetActiveFlag(battleStruct, 1);
    return 1;
}
