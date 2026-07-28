#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Combatant_20885b4;
int CheckFlag0x2AndKind1(struct Combatant_20885b4* obj);
struct S88514;
int CheckFlag0x2AndState2(struct S88514* obj);

// USA: func_ov024_021d8d38  (semantic: ComputeCombatantScaledValue_021d8d38)
extern "C" ARM int func_ov024_021d8d38(int a, int b, int id, int c, int d, int fallback) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    struct CombatantStruct* combatant = GetCombatantFromList(battleStruct, id);
    if (combatant == NULL) {
        return fallback;
    }
    if (CheckFlag0x2AndKind1((struct Combatant_20885b4*)combatant->currentStats) ||
        CheckFlag0x2AndState2((struct S88514*)combatant->currentStats) ||
        (*(int*)((char*)combatant->currentStats + 0x14) & 0x8) != 0) {
        return (int)(fallback * 1.5f);
    }
    return fallback;
}
