#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "std_library_functions.h"

// USA: func_020ac4c0
ARM int LoadBattleBlock020ac4c0(void* dst) {
    char* base;
    memset(dst, 0, 0xb0);
    base = (char*)GetBattleStruct() + 0x104 + 0x7400;
    memcpy(dst, base + 0x3c, 0xb0);
    return 1;
}
