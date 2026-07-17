#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void* GetPtrField0x2a04(struct BattleStruct* battleStruct);
struct CombatantStruct* GetCombatantWithFlag0x1000(struct BattleStruct* battleStruct, int combatantId);
int IsIdOrEffectMatchTarget0215fd24(void* p, int id);

// USA: func_ov024_021e5be4
ARM void ApplyFieldDeltaBySlot_021e5be4(void* a0, int id, void* a2) {
    struct BattleStruct* bs = GetBattleStruct();
    void* pf = GetPtrField0x2a04(bs);
    if (IsIdOrEffectMatchTarget0215fd24(*(void**)((char*)a0 + 0x10), id)) {
        short s = *(short*)((char*)a2 + 0x32);
        *(int*)((char*)pf + 0xf6c) -= s;
        return;
    }
    int cur;
    if (GetCombatantWithFlag0x1000(bs, id) != NULL) {
        id = 0;
        char* base = *(char**)((char*)a0 + 0x10);
        cur = *(int*)(base + 0x8000 + 0xe84);
    } else {
        char* base = *(char**)((char*)a0 + 0x10);
        cur = ((int*)(base + 0x284 + 0x8c00))[id];
    }
    char* base2 = *(char**)((char*)a0 + 0x10);
    short s = *(short*)((char*)a2 + 0x32);
    ((int*)(base2 + 0x284 + 0x8c00))[(short)id] = cur - s;
}
