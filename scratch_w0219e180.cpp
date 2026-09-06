#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Entry_02028bd0;
struct Entry_02028bd0* GetEntryTableBase(void);
extern "C" void* func_0202ae18(void);
int CheckField0NonZero(int* obj);
struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
struct Entry_02028bd0* FindInlineEntryById(struct Entry_02028bd0* base, int key);
struct CombatantStruct* GetCombatantWithFlag0x20(struct BattleStruct* battleStruct, int combatantId);
struct CombatantStruct* FindCombatantByField2_021a2738(void* unused, int value);
struct PairStruct;
void CopyFields0x8And0xC(struct PairStruct* src, struct PairStruct* dst);

struct EntryFlags_0219e180 { unsigned char pad0[2]; unsigned short field2 : 2; unsigned short pad3 : 14; };

// USA: func_ov017_0219e180
ARM void SyncMatchingCombatantPairs_0219e180(void* obj, int id) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    struct Entry_02028bd0* entryTable = GetEntryTableBase();
    void* search = func_0202ae18();

    if (CheckField0NonZero((int*)search)) {
        if (GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)search) != 0) {
            return;
        }
    }

    struct EntryFlags_0219e180* entry = (struct EntryFlags_0219e180*)FindInlineEntryById(entryTable, id);
    if (!entry) {
        return;
    }

    int base = 0xc * entry->field2 + 0x70;
    for (int i = 0; i < 0xc; i++) {
        struct CombatantStruct* combatant = GetCombatantWithFlag0x20(battleStruct, i + base);
        if (combatant) {
            short field2 = *(short*)((char*)combatant + 0x2);
            struct CombatantStruct* matched = FindCombatantByField2_021a2738(obj, field2);
            if (matched) {
                CopyFields0x8And0xC((struct PairStruct*)matched, (struct PairStruct*)combatant);
            }
        }
    }
}
