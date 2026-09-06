#include <globaldefs.h>
#include "Combat/Main/BattleList.h"


// USA: func_02039730
ARM int GetCombatSignedByteAt0x2c8d02039730(void* unused, int index) {
    char* p = (char*)GetPtrField0x2a04((struct BattleStruct*)(GetBattleStruct())) + index;
    return p[0x2c8d];
}
