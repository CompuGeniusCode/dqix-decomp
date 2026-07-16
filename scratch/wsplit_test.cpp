#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

ARM int TestSplit(void) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    char* p = (char*)battleStruct;
    p = p + 0x29c;
    p = p + 0x5400;
    return *(int*)(p + 4);
}
