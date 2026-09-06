#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_02010210
ARM int GetBattleTimerDelta(struct BattleStruct* battleStruct) {
    return *(int*)((char*)battleStruct + 0x3b8);
}
