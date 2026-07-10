#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"

extern "C" void* func_02010828(struct BattleStruct*);

// USA: func_02039768
ARM void CopyToBattleField02039768(int unused, void* src) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    memcpy((char*)func_02010828(battleStruct) + 0x2c8d, src, 7);
}
