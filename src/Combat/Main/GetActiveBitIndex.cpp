#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_020103e8
ARM int GetActiveBitIndex(struct BattleStruct* battleStruct) {
    return *(int*)((char*)battleStruct + 0x3e0);
}
