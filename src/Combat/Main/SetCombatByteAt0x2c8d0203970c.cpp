#include <globaldefs.h>
#include "Combat/Main/BattleList.h"


// USA: func_0203970c
ARM void SetCombatByteAt0x2c8d0203970c(void* unused, int index, int value) {
    char* p = (char*)GetPtrField0x2a04((struct BattleStruct*)(GetBattleStruct())) + index;
    p[0x2c8d] = (char)value;
}
