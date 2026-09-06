#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_02011538
ARM int GetByteField0x5721(struct BattleStruct* battleStruct) {
    return *(unsigned char*)((char*)battleStruct + 0x5721);
}
