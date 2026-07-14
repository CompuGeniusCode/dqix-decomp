#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" unsigned int* func_ov017_0218b5b0(void);
struct CombatantStruct* GetCombatantChecked(struct BattleStruct* battleStruct, int combatantId);
int HasFlaggedSlotBit22Set020855d0(unsigned char* actor);
void* GetPtrField0x114(void* obj);
int CheckLow5BitsEqual1(unsigned short* obj);
int CheckLow5BitsEqual2(unsigned short* obj);
int CheckLow5BitsEqual3(unsigned short* obj);
int CheckLow5BitsEqual4(unsigned short* obj);
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
unsigned char GetByte0x26c(char* obj);

// USA: func_0208aa28
ARM int CanCombatantReactToEffectCategory0208aa28(unsigned char* obj, int combatantId, int flag) {
    func_ov017_0218b5b0();
    struct BattleStruct* battle = GetBattleStruct();
    struct CombatantStruct* c1 = GetCombatantChecked(battle, combatantId);
    struct CombatantStruct* c2 = GetCombatantWithFlag0x100(battle, combatantId);
    if (c1 == NULL || (**(int**)((char*)c1 + 0x130) & 1)) {
        return 0;
    }
    if (HasFlaggedSlotBit22Set020855d0(*(unsigned char**)((char*)c2 + 0x150)) != 0 || flag != 0) {
        return 0;
    }
    unsigned short* field = (unsigned short*)GetPtrField0x114(c1);
    switch (obj[4]) {
        case 0:
            if (!CheckLow5BitsEqual1(field)) return 0;
            break;
        case 1:
            if (!CheckLow5BitsEqual2(field)) return 0;
            break;
        case 2:
            if (!CheckLow5BitsEqual3(field)) return 0;
            break;
        case 3:
            if (!CheckLow5BitsEqual4(field)) return 0;
            break;
        default:
            break;
    }
    struct CombatantStruct* c3 = GetCombatantAtField0x397c(battle);
    if (*(short*)((char*)c3 + 0xb2) == 0) {
        return 0;
    }
    return GetByte0x26c((char*)c3) == 0 ? 1 : 0;
}
