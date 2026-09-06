#include <globaldefs.h>
#include "System/Memory.h"
#include "Combat/Main/BattleList.h"

// USA: func_020ac760
ARM int CopyOutBattleRegion0x64f4(void* dst) {
    VectorizedInvertedMemcpy((char*)GetBattleStruct() + 0x64f4, dst, 0xad6);
    return 1;
}
