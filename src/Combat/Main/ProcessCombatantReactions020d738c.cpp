#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantReactionBits020d738c {
    unsigned short unused0 : 2;
    unsigned short reactionType : 4;
    unsigned short unused1 : 10;
};

extern "C" void func_020d6f9c(void* param0, int combatantId, int reason);

// USA: func_020d738c
ARM void ProcessCombatantReactions020d738c(void* param0) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    int id;
    for (id = 0; id < 0xc; id++) {
        int combatantId = id;
        if (id > 3) {
            combatantId = id + 0xbc;
        }
        struct CombatantStruct* combatant = GetCombatantFromList(battleStruct, combatantId);
        struct ModifiableCombatStats* currentStats;
        unsigned short flags;
        int reactionType;
        unsigned short hp;
        if (combatant == NULL) {
            continue;
        }
        currentStats = combatant->currentStats;
        flags = *(unsigned int*)currentStats->unk1;
        reactionType = ((struct CombatantReactionBits020d738c*)(currentStats->unk1 + 0xE))->reactionType;
        hp = currentStats->primaryStats.currHP;
        if (flags & 1) {
            continue;
        }
        if (hp == 0) {
            continue;
        }
        if (flags & 2) {
            func_020d6f9c(param0, combatantId, 0);
            continue;
        }
        if (flags & 0x10) {
            func_020d6f9c(param0, combatantId, 1);
            continue;
        }
        if (flags & 8) {
            func_020d6f9c(param0, combatantId, 3);
            continue;
        }
        if (flags & 0x20) {
            func_020d6f9c(param0, combatantId, 4);
            continue;
        }
        if ((flags & 0x80000) && reactionType == 6) {
            func_020d6f9c(param0, combatantId, 2);
        }
    }
}
