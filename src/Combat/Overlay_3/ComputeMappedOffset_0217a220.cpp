#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
int GetFieldAt0x150(unsigned char* obj);
short FindMappedMemberId02080468(void* obj, int id);

// USA: func_ov003_0217a220
ARM void ComputeMappedOffset_0217a220(unsigned char* obj) {
    short result = -1;
    struct BattleStruct* bs = GetBattleStruct();
    struct CombatantStruct* c = GetCombatantWithFlag0x800(bs, *(signed char*)(obj + 0x1043));
    if (c != NULL) {
        unsigned char* base = (unsigned char*)GetFieldAt0x150((unsigned char*)c);
        short id = FindMappedMemberId02080468(*(void**)(obj + 0x89c), 0x15);
        short diff = *(short*)(obj + 0x100e) - id;
        result = *(short*)(base + diff * 2 + 0x400 + 0x54);
    }
    *(short*)(obj + 0x103a) = result;
}
