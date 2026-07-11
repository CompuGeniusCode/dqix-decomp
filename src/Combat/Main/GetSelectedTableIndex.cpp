#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_0201035c
ARM int GetSelectedTableIndex(struct BattleStruct* battleStruct) {
    return *(int*)((char*)battleStruct + 0x3dc);
}
