#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"

// USA: func_020abf38
ARM int CopyOutBattleRegion0x75f0(void* dst) {
    memcpy(dst, (char*)GetBattleStruct() + 0x75f0, 0x4d0);
    return 1;
}
