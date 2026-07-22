#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void* GetPtrField0x2a04(struct BattleStruct* battleStruct);
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
void CopyByteField0x253To0x252(void* obj);
unsigned char GetByteField0x252(void* obj);
unsigned char GetField0x397cValue(struct BattleStruct* battleStruct);
extern "C" void _Z21ClearFieldBit02053fe4P9T02053fe4(void* obj, int field2, int flag);
int TryClearFlags0x130(unsigned char* obj, unsigned short flag);
extern "C" void func_ov017_021c9e00(int i, int one1, int zero, int one2);
extern "C" void func_ov017_02191108(int, int, int, int, int);
void SetByteField0x253(void* obj);
struct Obj020397cc;
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);

extern int data_ov017_021d82e0;

struct P130_0218d2f0 {
    unsigned int word0;
    unsigned short at4;
    unsigned short at6;
};

// USA: func_ov017_0218d2f0
ARM void UpdateFlaggedCombatantCaps_0218d2f0(int flag1, int flag2, int addAmount, int skipCheck) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    unsigned char* base = (unsigned char*)GetPtrField0x2a04(battleStruct);
    unsigned char count = base[0xf7c];
    int keepPending = 1;

    struct CombatantStruct* c = GetCombatantAtField0x397c(battleStruct);
    if (c) {
        CopyByteField0x253To0x252(c);
        if (!GetByteField0x252(c)) keepPending = 0;
    }

    for (unsigned char i = 0; i < count; i++) {
        signed char id = *(signed char*)(base + i + 0xf78);
        struct CombatantStruct* combatant = GetCombatantWithFlag0x100(battleStruct, id);
        if (!combatant) continue;
        if (skipCheck == 0 && id != GetField0x397cValue(battleStruct)) continue;

        if (flag1) {
            struct P130_0218d2f0* p1 = *(struct P130_0218d2f0**)((unsigned char*)combatant + 0x130);
            if (p1->word0 & 1) {
                _Z21ClearFieldBit02053fe4P9T02053fe4(combatant, 1, 1);
                TryClearFlags0x130((unsigned char*)combatant, 1);
            }
        }
        if (flag2) {
            struct P130_0218d2f0* p1 = *(struct P130_0218d2f0**)((unsigned char*)combatant + 0x130);
            unsigned int w = p1->word0;
            if (!(w & 1)) {
                if (w) p1->word0 = w & 4;
            }
        }
        if (addAmount) {
            struct P130_0218d2f0* p1 = *(struct P130_0218d2f0**)((unsigned char*)combatant + 0x130);
            if (!(p1->word0 & 1)) {
                int cap4 = combatant->baseStats->primaryStats.maxHP;
                int n4 = p1->at4 + addAmount;
                if (cap4 < n4) n4 = cap4;
                p1->at4 = n4;

                struct P130_0218d2f0* p1b = *(struct P130_0218d2f0**)((unsigned char*)combatant + 0x130);
                int cap6 = combatant->baseStats->primaryStats.maxMP;
                int n6 = p1b->at6 + addAmount;
                if (cap6 < n6) n6 = cap6;
                p1b->at6 = n6;
            }
        }

        func_ov017_021c9e00(id, 1, 0, 1);
        func_ov017_02191108(*(int*)((char*)&data_ov017_021d82e0 + 4), 1, 1, 1, 1);
    }

    struct CombatantStruct* c2 = GetCombatantAtField0x397c(battleStruct);
    if (c2) {
        if (keepPending) SetByteField0x253(c2);
        else CancelPendingAction020397cc((struct Obj020397cc*)c2, 1);
    }
}
