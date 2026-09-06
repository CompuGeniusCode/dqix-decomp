#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_020100c4
ARM void SetField0x3b0Value(struct BattleStruct* battleStruct, int value) {
    *(int*)((char*)battleStruct + 0x3b0) = value;
}
