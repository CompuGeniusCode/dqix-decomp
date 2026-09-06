#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetFieldAt0x150(unsigned char* obj);
int TestBitInArray0x8ec(unsigned char* obj, int index);

struct Sub130_02048350 {
    char pad[0x6];
    unsigned short count;
};

struct Obj02048350 {
    char pad0[0x4];
    short combatantId;
    char pad1[0x130 - 0x6];
    struct Sub130_02048350* sub;
};

// USA: func_02048350
ARM int ConsumeCounter02048350(struct Obj02048350* obj, int amount) {
    struct Sub130_02048350* sub = obj->sub;
    unsigned short count = sub->count;
    struct BattleStruct* bs = GetBattleStruct();
    struct CombatantStruct* combatant = GetCombatantWithFlag0x100(bs, obj->combatantId);
    if (combatant != NULL && amount > 0) {
        unsigned char* ptr = (unsigned char*)GetFieldAt0x150((unsigned char*)combatant);
        if (ptr != NULL && TestBitInArray0x8ec(ptr, 0x106)) {
            amount = (int)(0.75f + 0.75f * (float)amount);
            if (amount <= 0) {
                amount = 0;
            }
        }
    }
    if (count <= amount) {
        obj->sub->count = 0;
        return count;
    }
    obj->sub->count = count - amount;
    return amount;
}
