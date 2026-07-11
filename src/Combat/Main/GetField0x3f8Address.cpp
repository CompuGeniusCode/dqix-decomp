#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_0200fd0c
ARM void* GetField0x3f8Address(struct BattleStruct* battleStruct) {
    return (char*)battleStruct + 0x3f8;
}
