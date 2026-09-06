#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_02010220
ARM unsigned int GetBattleScaleCount(struct BattleStruct* battleStruct) {
    return *(unsigned int*)((char*)battleStruct + 0x3c4);
}
