#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Util/Random.h"

int ClassifyField0x81fe(char* base);
extern "C" int func_ov000_02155f9c(struct Random* rand, int combatantId, int checkSubFlag);
struct CombatantStruct* GetCombatantWithFlag0x100(struct BattleStruct* battleStruct, int combatantId);
int IsFlag0x18Bit0x400Set(struct CombatantStruct* combatant);
int TestBitInArray0x8ec(unsigned char* obj, int index);
int NextRandomMax(struct Random* random, int maximum);

extern unsigned char data_ov000_02182ab8[];

// USA: func_ov000_02156558  (semantic: RollHitOrEvasionChance_02156558)
extern "C" ARM int func_ov000_02156558(struct Random* rand, int combatantId) {
    if (ClassifyField0x81fe((char*)rand) != 0) {
        return 0;
    }

    struct BattleStruct* bs = GetBattleStruct();
    int inRange = (combatantId >= 0 && combatantId <= 3) ? 1 : 0;
    if (!inRange) {
        return 0;
    }

    if (func_ov000_02155f9c(rand, combatantId, 0) != 0) {
        return 0;
    }

    struct CombatantStruct* c = GetCombatantWithFlag0x100(bs, combatantId);
    if (c == 0) {
        return 0;
    }

    if (IsFlag0x18Bit0x400Set(c)) {
        short val = *(short*)((char*)rand + 0x8e00 + 0x6e);
        if (val >= 0x32) {
            if (val < 0x4b) return 1;
        }
        return 0;
    }

    if (TestBitInArray0x8ec(*(unsigned char**)((char*)c + 0x150), 0x36) == 0) {
        return 0;
    }

    int idx = *(int*)((char*)(*(void**)((char*)c + 0x150)) + 0x950);
    int maxVal = data_ov000_02182ab8[idx];
    return NextRandomMax(rand, maxVal) == 1;
}
