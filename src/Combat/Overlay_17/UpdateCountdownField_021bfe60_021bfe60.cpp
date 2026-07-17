#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetField0x3b4Value(struct BattleStruct* battleStruct);
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
void SetByteField0x253(void* obj);
int GetFieldIfFlag4(char* obj);
void SetField0x23cTrue(void* obj);
void ClearBitsInField4(unsigned int* obj, unsigned int mask);

extern "C" void* func_ov017_0218b5b0(void);

// USA: func_ov017_021bfe60
ARM int UpdateCountdownField_021bfe60_021bfe60(unsigned char* self) {
    struct BattleStruct* battle = GetBattleStruct();
    int value = GetField0x3b4Value(battle);
    unsigned short* field8 = (unsigned short*)(self + 8);
    if ((unsigned int)value < (unsigned int)*field8) {
        *field8 = *field8 - value;
        return 5;
    }

    *field8 = 0;
    struct CombatantStruct* combatant = GetCombatantAtField0x397c(battle);
    if (combatant != NULL) {
        SetByteField0x253(combatant);
    }
    void* ov = func_ov017_0218b5b0();
    int flag = GetFieldIfFlag4((char*)battle);
    if (flag != 0) {
        SetField0x23cTrue((void*)flag);
    }
    if (ov != NULL) {
        ClearBitsInField4((unsigned int*)ov, 0x80);
    }
    *field8 = 0x12c;
    return 6;
}
