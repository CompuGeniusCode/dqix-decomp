#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
extern "C" void func_ov017_021cf730(int a, int b);
extern "C" void func_ov017_021c4fa0(int a, int b);
struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);
struct U16Field0x6_020375f8;
unsigned short GetU16At0x6(struct U16Field0x6_020375f8* obj);
void EnqueueEventTag147_021cdaa0(void);

struct Evt021cd9e8 {
    unsigned char pad0[4];
    unsigned char lowNibble : 4;
    unsigned char highNibble : 4;
    unsigned char pad5[3];
    int flags8;
};

// USA: func_ov017_021cd9e8  (semantic: ApplyEventTagWithCombatant_021cd9e8)
extern "C" ARM void func_ov017_021cd9e8(int p0, struct Evt021cd9e8* evt, struct BattleStruct* battleStruct, int p3, struct SearchStruct0202c1a4* search) {
    signed char cur = GetSearchStructCurrentArrEntry(search);
    if (evt->lowNibble != cur) return;

    if (evt->flags8 & 0x1) {
        EnqueueEventTag147_021cdaa0();
    }
    if (evt->flags8 & 0x20) {
        func_ov017_021cf730((signed char)evt->highNibble, 0);
    }

    int val = -1;
    if (evt->flags8 & 0x10) {
        signed char idx = GetSearchStructCurrentArrEntry(search);
        struct CombatantStruct* combatant = GetCombatantUnchecked(battleStruct, idx);
        if (combatant != NULL) {
            val = GetU16At0x6((struct U16Field0x6_020375f8*)combatant);
        }
    }

    if (!(evt->flags8 & 0x4)) return;
    func_ov017_021c4fa0(evt->highNibble, val);
}
