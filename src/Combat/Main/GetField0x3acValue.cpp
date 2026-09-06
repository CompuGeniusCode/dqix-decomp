#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: _Z18GetField0x3acValueP12BattleStruct
ARM int GetField0x3acValue(struct BattleStruct* battleStruct) {
    return *(int*)((char*)battleStruct + 0x3ac);
}
