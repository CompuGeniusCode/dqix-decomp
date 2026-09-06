#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantAtField0x3ac(struct BattleStruct* battleStruct);
int GetFieldAt0x150(unsigned char* obj);

struct Sub0x150_02161d54 {
    char pad[0x49c];
    unsigned char bit0 : 1;
};

extern "C" int func_ov017_021d6134(void* obj, int flag);

// USA: func_ov001_02161d54
ARM int SetFlagFromInverseBit49c_02161d54(void* obj) {
    struct CombatantStruct* combatant = GetCombatantAtField0x3ac(GetBattleStruct());
    struct Sub0x150_02161d54* sub = (struct Sub0x150_02161d54*)GetFieldAt0x150((unsigned char*)combatant);
    int flag = sub->bit0 ? 0 : 1;
    func_ov017_021d6134(obj, flag);
    return 1;
}
