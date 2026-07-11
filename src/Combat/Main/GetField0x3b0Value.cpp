#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_020100bc
ARM int GetField0x3b0Value(struct BattleStruct* battleStruct) {
    return *(int*)((char*)battleStruct + 0x3b0);
}
