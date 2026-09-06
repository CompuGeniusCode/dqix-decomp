#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov001_0215b040
ARM int SetBattleFlagField5cac_0215b040() {
    *(unsigned char*)((char*)GetBattleStruct() + 0x5000 + 0xcac) = 1;
    return 1;
}
