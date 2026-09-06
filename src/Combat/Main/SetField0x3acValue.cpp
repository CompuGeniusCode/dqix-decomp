#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_020100a0
ARM void SetField0x3acValue(struct BattleStruct* battleStruct, int value) {
    *(int*)((char*)battleStruct + 0x3ac) = value;
}
