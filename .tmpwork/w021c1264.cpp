#include <globaldefs.h>

struct BattleStruct;
struct BattleStruct* GetBattleStruct(void);
extern "C" int func_ov017_0218b5b0(void);
struct CombatantStruct;
struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
extern "C" void func_ov017_02191fec(void* base, int id);

// USA: func_ov017_021c1264
ARM void NotifyFlaggedCombatants_021c1264(void) {
    struct BattleStruct* bs = GetBattleStruct();
    int base = func_ov017_0218b5b0();
    for (int i = 0; i < 4; i++) {
        if (GetCombatantWithFlag0x800(bs, i) != 0) {
            func_ov017_02191fec((void*)(long)base, i);
        }
    }
}
