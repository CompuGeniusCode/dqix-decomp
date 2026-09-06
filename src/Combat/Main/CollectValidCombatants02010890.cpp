#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantChecked(struct BattleStruct* battleStruct, int combatantId);

// USA: func_02010890
ARM void CollectValidCombatants02010890(struct BattleStruct* bs, int* outList, int* outCount) {
    int count = 0;
    int i;
    for (i = 0; i < 4; i++) {
        if (GetCombatantChecked(bs, i)) {
            outList[count] = i;
            count++;
        }
    }
    *outCount = count;
}
