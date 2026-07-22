#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);

struct U16Field0x6_020375f8;
unsigned short GetU16At0x6(struct U16Field0x6_020375f8* obj);

struct Obj_021bd3a4;
int HasFlag3orFlag2And9a_021bd3a4(struct Obj_021bd3a4* obj);

void SetFlag0x6cBit0(unsigned char* obj);
void ClearFlag0x1InField0x6c(unsigned char* obj);

extern "C" unsigned short* func_02012fe4(void);
extern "C" void func_020dc548(signed char id, signed char* ids, signed char* count);

struct IdList_021bd4d0 {
    signed char count;
    signed char ids[7];
};

// USA: func_ov017_021bd4d0
ARM void UpdateFlag6cForRelatedCombatants_021bd4d0(void* self, int index, int flag, int val) {
    unsigned char* base = (unsigned char*)self;
    struct BattleStruct* battle = GetBattleStruct();
    struct CombatantStruct* combatant = GetCombatantWithFlag0x800(battle, index);
    if (!combatant) return;

    int ok = 1;
    unsigned short g = *func_02012fe4();
    unsigned short v = GetU16At0x6((struct U16Field0x6_020375f8*)combatant);
    if (v != g) {
        if (flag == 0) ok = 0;
    }

    if (HasFlag3orFlag2And9a_021bd3a4((struct Obj_021bd3a4*)self)) {
        if (*(unsigned short*)(base + 0x16) == 0x2972 || *(unsigned char*)(base + 0x101) == 0) {
            val = 0;
        }
    }

    if (!ok) return;
    if (val != 0) {
        if (HasFlag3orFlag2And9a_021bd3a4((struct Obj_021bd3a4*)self)) return;
    }

    struct IdList_021bd4d0 list;
    func_020dc548((signed char)index, list.ids, &list.count);
    for (int i = 0; i < list.count; i++) {
        struct CombatantStruct* c = GetCombatantWithFlag0x800(battle, list.ids[i]);
        if (c) {
            if (flag) {
                ClearFlag0x1InField0x6c((unsigned char*)c);
            } else {
                SetFlag0x6cBit0((unsigned char*)c);
            }
        }
    }
}
