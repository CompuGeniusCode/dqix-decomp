#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x2(struct BattleStruct* battleStruct, int combatantId);
int CheckFlag0x6cBit0Clear(unsigned char* obj);
struct List_02028430;
struct ListEntry_02028430;
ListEntry_02028430* GetListEntryChecked(List_02028430* list, int index);

struct KindField02073d58 {
    unsigned short kind : 2;
    unsigned short pad : 14;
};

// USA: func_02073d58
ARM int CheckAnySlotMatchesId02073d58(int a, void* b, int c) {
    struct BattleStruct* bs = GetBattleStruct();
    int i;
    for (i = 0; i < 0xc; i++) {
        int kind = ((struct KindField02073d58*)((char*)b + 2))->kind;
        int tmp = kind * 12 + 0x70;
        int id = i + tmp;
        if (c != -1 && id == c) continue;
        struct CombatantStruct* combatant = GetCombatantWithFlag0x2(bs, id);
        if (!combatant) continue;
        if (!CheckFlag0x6cBit0Clear((unsigned char*)combatant)) continue;
        unsigned short field_b8 = *(unsigned short*)((char*)combatant + 0xb8);
        ListEntry_02028430* entry = GetListEntryChecked((List_02028430*)((char*)b + 0x18), field_b8);
        if (!entry) continue;
        if (*(unsigned char*)entry == a) return 1;
    }
    return 0;
}
