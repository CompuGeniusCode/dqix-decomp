#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "std_library_functions.h"

// USA: func_020ac0dc
ARM int ClearBattleRegion0x7ac4() {
    struct BattleStruct* bs = GetBattleStruct();
    memset((char*)bs + 0x7ac4, 0, 0x3ae);
    return 1;
}
