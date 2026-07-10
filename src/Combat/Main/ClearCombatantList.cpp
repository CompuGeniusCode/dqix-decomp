#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"

// USA: func_0200fd58
ARM void* ClearCombatantList(struct BattleStruct* battleStruct) {
    return memset(battleStruct->combatantList, 0, 0x3a4);
}
