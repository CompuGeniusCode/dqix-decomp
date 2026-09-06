#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x400(struct BattleStruct* battleStruct, int combatantId);

// USA: func_ov000_0216352c
ARM short ClampScaledStat_0216352c(int id, float a, float b) {
    struct BattleStruct* bs = GetBattleStruct();
    int inRange = (id >= 0xc0 && id <= 0xc7);
    if (!(inRange && bs != NULL)) {
        return 0x10a;
    }
    struct CombatantStruct* c = GetCombatantWithFlag0x400(bs, id);
    if (c == NULL) {
        return 0x10a;
    }
    short baseline = *(short*)((char*)c + 0x100 + 0x8e);
    int lo = (int)(a * 4096.0f);
    if (baseline <= lo) {
        return baseline;
    }
    int hi = (int)(b * 4096.0f);
    int delta = baseline - lo;
    int rounded = (int)(((long long)delta * hi + 0x800) >> 12);
    return (short)(lo + rounded);
}
