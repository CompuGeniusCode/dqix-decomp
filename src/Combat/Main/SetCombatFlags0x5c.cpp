#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);

struct Struct0203cedc {
    char pad0[0xc];
    int fieldC;
    char pad1[0x5c - 0x10];
    int flags5c;
    char pad2[0x98 - 0x60];
    int field98;
};

// USA: func_0203cedc
ARM void SetCombatFlags0x5c(struct Struct0203cedc* obj, int b, int c) {
    struct BattleStruct* battleStruct;
    struct CombatantStruct* combatant;

    battleStruct = GetBattleStruct();
    combatant = GetCombatantAtField0x397c(battleStruct);

    if (*(int*)((char*)combatant + 0x4c) >= obj->fieldC) {
        return;
    }

    obj->field98 = *(int*)((char*)combatant + 0x44);
    obj->flags5c &= ~0x20;
    obj->flags5c &= ~0x10;

    if (b != 0) {
        if (c == 0) {
            obj->flags5c |= 0x10;
            return;
        }
    }

    if ((b & c) != 0) {
        obj->flags5c |= 0x20;
    }
}
