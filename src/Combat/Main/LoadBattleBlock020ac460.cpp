#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "std_library_functions.h"

// USA: func_020ac460
ARM int LoadBattleBlock020ac460(void* dst) {
    memset(dst, 0, 0x3c);
    memcpy(dst, (char*)GetBattleStruct() + 0x104 + 0x7400, 0x3c);
    return 1;
}
