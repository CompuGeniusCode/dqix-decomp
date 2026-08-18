#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Combat/Main/BattleList.h"

extern "C" int func_ov017_021d60f4(void*);
int AbsPlus159IfNegative0215ad2c(int x);
struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);
struct Container02037364;
void RemoveMatchingNodes02037364(struct Container02037364* obj, int key);
extern "C" int func_02036e34(void*, int, int);
extern int data_ov001_02165769;

// USA: func_ov001_0215bcc0  (semantic: RemoveCombatantEntry_0215bcc0)
extern "C" ARM int func_ov001_0215bcc0(void* self, int mode) {
    struct BattleStruct* battle = GetBattleStruct();
    (int)BackgroundLoader::GetInstance();
    int mode2;
    int id = AbsPlus159IfNegative0215ad2c(func_ov017_021d60f4(self));
    mode2 = 3;
    if (mode >= 2) {
        mode2 = func_ov017_021d60f4((char*)self + 0x8);
    }
    struct CombatantStruct* combatant = GetCombatantUnchecked(battle, id);
    if (combatant == NULL) return 0;
    unsigned char byteField = *((unsigned char*)combatant + 0x19);
    void* ptrField = *(void**)((char*)combatant + 0x14);
    RemoveMatchingNodes02037364((struct Container02037364*)combatant, mode2);
    if (func_02036e34(combatant, (int)ptrField, byteField) == 0) {
        func_02036e34(combatant, (int)&data_ov001_02165769, 0);
    }
    return 1;
}
