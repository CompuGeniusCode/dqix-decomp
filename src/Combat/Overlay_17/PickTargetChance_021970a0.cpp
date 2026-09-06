#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Util/Random.h"

void* GetPtrField0x2a04(struct BattleStruct* battleStruct);
struct CombatantStruct* GetCombatantWithFlag0x100(struct BattleStruct* battleStruct, int combatantId);
void* GetFieldAt0x150(unsigned char* obj);
extern "C" int func_02032370(int max);

struct RandomTargetTable021970a0 {
    char pad[0xf78];
    unsigned char ids[4];
    unsigned char count;
};

struct Field150LowBits021970a0 {
    unsigned int lowBits : 10;
    unsigned int rest : 22;
};

// USA: func_ov017_021970a0  (semantic: PickTargetChance_021970a0)
extern "C" ARM int func_ov017_021970a0(int mode) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    GetBTRandom();
    struct RandomTargetTable021970a0* table = (struct RandomTargetTable021970a0*)GetPtrField0x2a04(battleStruct);

    int maxVal = 0;
    for (int i = 0; i < table->count; i++) {
        struct CombatantStruct* c = GetCombatantWithFlag0x100(battleStruct, table->ids[i]);
        if (c == NULL) continue;
        int* p130 = *(int**)((char*)c + 0x130);
        if (*p130 & 1) continue;
        void* fp = GetFieldAt0x150((unsigned char*)c);
        if (fp == NULL) continue;
        unsigned int v = ((struct Field150LowBits021970a0*)((char*)fp + 4))->lowBits;
        if (maxVal < v) maxVal = v;
    }

    if (mode != 2) {
        float extra = (mode == 1) ? 10.0f : 0.0f;
        float threshold = 2.0f + 0.05f * (float)maxVal + extra;
        int t = (int)threshold;
        if (func_02032370(100) < t) return 1;
    }
    if (mode == 1) goto ret0;

    {
        float extra2 = (mode == 2) ? 10.0f : 0.0f;
        float threshold2 = 2.0f + extra2;
        int t2 = (int)threshold2;
        if (func_02032370(100) < t2) return 2;
    }
ret0:
    return 0;
}
