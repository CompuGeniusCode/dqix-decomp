#include <globaldefs.h>
#include "System/Memory.h"
#include "Combat/Main/BattleList.h"

// USA: func_020ac78c
ARM int CopyOutBattleField0x64f4(void* dst) {
    VectorizedInvertedMemcpy((char*)GetBattleStruct() + 0x64f4, dst, 1);
    return 1;
}
