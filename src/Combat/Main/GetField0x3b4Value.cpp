#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_02010208
ARM int GetField0x3b4Value(struct BattleStruct* battleStruct) {
    return *(int*)((char*)battleStruct + 0x3b4);
}
