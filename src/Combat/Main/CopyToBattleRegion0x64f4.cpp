#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "System/Memory.h"

// USA: func_020ac734
ARM int CopyToBattleRegion0x64f4(void* arg) {
    struct BattleStruct* bs = GetBattleStruct();
    VectorizedInvertedMemcpy(arg, (char*)bs + 0x64f4, 0xad6);
    return 1;
}
