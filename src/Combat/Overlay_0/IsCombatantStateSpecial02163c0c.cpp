#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x400(struct BattleStruct* battleStruct, int combatantId);

// USA: func_ov000_02163c0c
#pragma optimize_for_size off
ARM int IsCombatantStateSpecial02163c0c(void* unused, int id) {
    struct BattleStruct* battle = GetBattleStruct();
    int valid = (id >= 0xc0 && id <= 0xc7);
    struct CombatantStruct* c;
    int x;
    short state;
    if (!valid) goto fail;
    c = GetCombatantWithFlag0x400(battle, id);
    if (!c) goto fail;
    x = 0x1fd;
    state = *(short*)((char*)c + 2);
    if (state == x || state == x + 1 || (unsigned int)(state - 0x308) <= 3) return 1;
fail:
    return 0;
}
