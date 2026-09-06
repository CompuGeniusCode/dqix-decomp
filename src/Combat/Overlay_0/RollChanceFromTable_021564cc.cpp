#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Util/Random.h"

struct CombatantStruct* GetCombatantWithFlag0x100(struct BattleStruct* battleStruct, int combatantId);
int TestBitInArray0x8ec(unsigned char* obj, int index);
extern unsigned char data_ov000_02182ac5[];

struct Field150_021564cc {
    char pad[0x950];
    int idx;
};

// USA: func_ov000_021564cc
ARM int RollChanceFromTable_021564cc(struct Random* rand, int id) {
    struct BattleStruct* bs = GetBattleStruct();
    int inRange = (id >= 0 && id <= 3);
    if (!inRange) return 0;
    struct CombatantStruct* combatant = GetCombatantWithFlag0x100(bs, id);
    if (combatant == NULL) return 0;
    unsigned char* field150 = *(unsigned char**)((char*)combatant + 0x150);
    if (!TestBitInArray0x8ec(field150, 0xd0)) return 0;
    struct Field150_021564cc* field150b = *(struct Field150_021564cc**)((char*)combatant + 0x150);
    int idx = field150b->idx;
    int tableVal = data_ov000_02182ac5[idx];
    int pick = NextRandomMax(rand, tableVal);
    return (pick == 1);
}
