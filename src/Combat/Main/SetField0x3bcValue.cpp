#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_02010228
ARM void SetField0x3bcValue(struct BattleStruct* battleStruct, short value) {
    *(short*)((char*)battleStruct + 0x3bc) = value;
}
