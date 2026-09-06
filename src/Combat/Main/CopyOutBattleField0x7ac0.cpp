#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"

// USA: func_020ac0b4
ARM int CopyOutBattleField0x7ac0(void* dst) {
    memcpy(dst, (char*)GetBattleStruct() + 0x7ac0, 4);
    return 1;
}
