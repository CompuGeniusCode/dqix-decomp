#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_02010218
ARM int GetFieldAt0x3c0(struct BattleStruct* battleStruct) {
    return *(int*)((char*)battleStruct + 0x3c0);
}
