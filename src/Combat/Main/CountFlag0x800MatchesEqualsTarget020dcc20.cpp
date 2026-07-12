#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
int GetFieldAt0x150(unsigned char* obj);

// USA: func_020dcc20
ARM int CountFlag0x800MatchesEqualsTarget020dcc20(int targetCount, int flag) {
    struct BattleStruct* battle = GetBattleStruct();
    unsigned char count = 0;
    for (signed char i = 0; i < 4; i++) {
        struct CombatantStruct* c = GetCombatantWithFlag0x800(battle, i);
        if (c != NULL) {
            if (!(flag != 0 && *(int*)((char*)c + 0x1c4) != 0)) {
                if (GetFieldAt0x150((unsigned char*)c) != 0) {
                    count = count + 1;
                }
            }
        }
    }
    return count == targetCount;
}
