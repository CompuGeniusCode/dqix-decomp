#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_020100a8
ARM int GetField0x3acValue(struct BattleStruct* battleStruct) {
    return *(int*)((char*)battleStruct + 0x3ac);
}
