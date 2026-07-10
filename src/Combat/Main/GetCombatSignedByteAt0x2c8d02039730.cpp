#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" char* func_02010828(struct BattleStruct* battleStruct);

// USA: func_02039730
ARM int GetCombatSignedByteAt0x2c8d02039730(void* unused, int index) {
    char* p = func_02010828(GetBattleStruct()) + index;
    return p[0x2c8d];
}
