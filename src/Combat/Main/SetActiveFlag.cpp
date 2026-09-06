#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_02010354
ARM void SetActiveFlag(struct BattleStruct* battleStruct, int active) {
    *(int*)((char*)battleStruct + 0x3d8) = active;
}
