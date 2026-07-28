#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct BattleStruct* GetBattleStruct(void);
struct CombatantStruct* GetCombatantWithFlag0x100(struct BattleStruct* battleStruct, int combatantId);
void* GetData02108ea8(void);
struct Entry0207d9bc;
struct Entry0207d9bc* FindEntryByHalfword(struct Entry0207d9bc* arr, unsigned short key);

extern unsigned char data_ov017_021d7654[4];

// USA: func_ov017_021a1a20  (semantic: AssignUniqueEventId_021a1a20)
extern "C" ARM unsigned short func_ov017_021a1a20(void) {
    struct BattleStruct* bs = GetBattleStruct();
    void* table = GetData02108ea8();
    int i;
retry:
    if (*(unsigned short*)(data_ov017_021d7654 + 2) > 0x7fff) {
        *(unsigned short*)(data_ov017_021d7654 + 2) = 0x7ff8;
    }
    for (i = 0; i < 4; i++) {
        struct CombatantStruct* c = GetCombatantWithFlag0x100(bs, i);
        if (c != NULL) {
            unsigned short field = *(unsigned short*)((char*)c + 0x1b2);
            if (*(unsigned short*)(data_ov017_021d7654 + 2) == field) {
                *(unsigned short*)(data_ov017_021d7654 + 2) = *(unsigned short*)(data_ov017_021d7654 + 2) + 1;
                goto retry;
            }
        }
    }
    if (FindEntryByHalfword((struct Entry0207d9bc*)table, *(unsigned short*)(data_ov017_021d7654 + 2)) != NULL) {
        *(unsigned short*)(data_ov017_021d7654 + 2) = *(unsigned short*)(data_ov017_021d7654 + 2) + 1;
        goto retry;
    }
    unsigned short result = *(unsigned short*)(data_ov017_021d7654 + 2);
    *(unsigned short*)(data_ov017_021d7654 + 2) = result + 1;
    return result;
}
