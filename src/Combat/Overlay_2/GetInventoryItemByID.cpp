#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" struct CombatantStruct* GetCombatantWithFlag0x100(struct BattleStruct* battleStruct, int combatantId);

extern "C" void* GetPlayerData(struct BattleStruct* battleStruct);
extern "C" int GetCombatantRecord(unsigned char* obj);

inline char* AddOffset204(char* p) { return p + 0x204; }
inline char* AddOffsetC00(char* p) { return p + 0xc00; }

// USA: func_ov002_0215707c
extern "C" ARM int GetInventoryItemByID(void* self, int idx, int kind) {
    if (idx < 0) {
        return -1;
    }
    if (kind < 0) {
        return -1;
    }
    struct BattleStruct* battle = GetBattleStruct();
    if (kind == 5) {
        char* p = (char*)GetPlayerData(battle);
        char* table = AddOffsetC00(AddOffset204(p));
        return *(short*)(table + 0xc + idx * 2);
    }
    if (kind == 4) {
        char* p = (char*)GetPlayerData(battle);
        return *(short*)(p + 0xc + idx * 2);
    }
    signed char id = *(signed char*)((char*)self + 0x1c20);
    struct CombatantStruct* combatant = GetCombatantWithFlag0x100(battle, id);
    if (combatant == 0) {
        return -1;
    }
    return *(short*)((char*)GetCombatantRecord((unsigned char*)combatant) + 0x454 + idx * 2);
}
