#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Util/Random.h"

// USA: func_ov024_021d95e0
ARM int SetFlagOrScale99Percent_021d95e0(struct Random** rngPtr, int unused1, int combatantId, int unused3, int unused4, volatile int value) {
    struct BattleStruct* bs = GetBattleStruct();
    struct CombatantStruct* c = GetCombatantFromList(bs, combatantId);
    if (!c) return value;
    if (NextRandomMax(*rngPtr, 2) > 0) {
        *((unsigned char*)(*rngPtr) + 0x8e94) = 1;
        return 0xffff;
    }
    unsigned short hp = *(unsigned short*)((char*)c->currentStats + 0);
    return (int)((float)hp * 0.99f);
}
