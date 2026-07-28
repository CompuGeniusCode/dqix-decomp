#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Outer_02054000;
void* GetActiveSub_02054000(struct Outer_02054000* p);
extern "C" int func_ov000_0217538c(void* objRaw);

struct Data0217c2a0 {
    int field0;
    int field4;
    void* field8;
};
extern Data0217c2a0 data_ov000_02184294;

// USA: func_ov000_0217c2a0  (semantic: CheckCombatantConditions_0217c2a0)
extern "C" ARM int func_ov000_0217c2a0(void* objRaw) {
    char* obj = (char*)objRaw;
    int result = 0;
    struct BattleStruct* battleStruct = GetBattleStruct();
    int combId = *(int*)(obj + 0x4c);
    struct CombatantStruct* combatant = GetCombatantWithFlag0x100(battleStruct, combId);
    if (combatant != 0) {
        void* sub = GetActiveSub_02054000((struct Outer_02054000*)combatant);
        if (sub != 0) {
            short val = *(short*)((char*)sub + 0x18);
            if (val > 0) {
                struct Bits02f4 { unsigned int bit0 : 1; unsigned int bit1 : 1; unsigned int hi : 30; };
                struct Bits02f4* bits = (struct Bits02f4*)(*(int*)((char*)combatant + 0x150) + 0x2f4);
                if (bits->bit1) {
                    result = 1;
                } else {
                    if (bits->bit0) {
                        if (func_ov000_0217538c(data_ov000_02184294.field8) == 1) {
                            result = 1;
                        }
                    }
                }
            }
        }
        if (data_ov000_02184294.field0 == 1) {
            result = 1;
        }
    }
    return result;
}
