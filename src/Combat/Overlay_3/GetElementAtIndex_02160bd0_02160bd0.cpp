#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov003_02160bd0
ARM void* GetElementAtIndex_02160bd0_02160bd0(void* unused, int index) {
    if (index < 0) return NULL;
    void* p = GetPtrField0x2a04(GetBattleStruct());
    return (char*)p + 0xf80 + index * 0x23c;
}
