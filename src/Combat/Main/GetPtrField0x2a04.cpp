#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_02010828
ARM void* GetPtrField0x2a04(struct BattleStruct* battleStruct) {
    return (char*)battleStruct + 0x2a04;
}
