#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void* GetData02108ea8(void);
struct CombatantStruct* GetCombatantWithFlag0x100(struct BattleStruct* battleStruct, int combatantId);
struct Entry0207d9bc;
struct Entry0207d9bc* FindEntryByHalfword(struct Entry0207d9bc* arr, unsigned short key);

struct Data021d7654 {
    unsigned char pad0[2];
    unsigned short key;
};
extern struct Data021d7654 data_ov017_021d7654;

// USA: func_ov017_021a1a20
ARM void AssignUniqueEntryKey_021a1a20(void) {
    struct Data021d7654* data;
    unsigned int limit;
    unsigned int maxLimit;
    struct BattleStruct* battleStruct = GetBattleStruct();
    struct Entry0207d9bc* table = (struct Entry0207d9bc*)GetData02108ea8();
    limit = 0x7ff8;
    data = &data_ov017_021d7654;
    maxLimit = limit + 7;

outerLoop:
    if ((unsigned short)data->key > maxLimit) {
        data->key = (unsigned short)limit;
    }

    {
        int i;
        for (i = 0; i < 4; i++) {
            struct CombatantStruct* combatant = GetCombatantWithFlag0x100(battleStruct, i);
            if (combatant != 0) {
                unsigned short val = *(unsigned short*)((char*)combatant + 0x100 + 0xb2);
                if (data->key == val) {
                    data->key = data->key + 1;
                    goto outerLoop;
                }
            }
        }
    }

    {
        struct Entry0207d9bc* entry = FindEntryByHalfword(table, data->key);
        if (entry != 0) {
            data->key = data->key + 1;
            goto outerLoop;
        }
    }

    data_ov017_021d7654.key = data_ov017_021d7654.key + 1;
}
