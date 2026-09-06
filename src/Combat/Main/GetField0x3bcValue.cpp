#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_02010234
ARM short GetField0x3bcValue(struct BattleStruct* battleStruct) {
    return *(short*)((char*)battleStruct + 0x3bc);
}
