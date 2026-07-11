#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_02010280
ARM float GetAccumulatedValue(struct BattleStruct* battleStruct) {
    return *(float*)((char*)battleStruct + 0x3cc);
}
