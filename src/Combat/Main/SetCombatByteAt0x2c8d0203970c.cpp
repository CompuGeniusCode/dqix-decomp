#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" char* func_02010828(struct BattleStruct* battleStruct);

// USA: func_0203970c
ARM void SetCombatByteAt0x2c8d0203970c(void* unused, int index, int value) {
    char* p = func_02010828(GetBattleStruct()) + index;
    p[0x2c8d] = (char)value;
}
