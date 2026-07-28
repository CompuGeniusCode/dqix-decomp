#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Field150Holder02052df8;
struct Container020dedd0;
struct Element020de650;

struct CombatantStruct* GetCombatantWithFlag0x100(struct BattleStruct* battleStruct, int combatantId);
int GetHalfwordEntryFromField150(struct Field150Holder02052df8* obj, int index);
struct Element020de650* FindElementByKey020dedd0(struct Container020dedd0* c, int key);

struct Table9x0217fb68 { unsigned int v[9]; };
extern struct Table9x0217fb68 data_ov003_0217fb68;

struct Ctx02179cfc {
    char pad[8];
    unsigned int idx4 : 4;
    unsigned int fieldRest : 28;
};

// USA: func_ov003_02179cfc  (semantic: SelectAndApplyEntry_02179cfc)
extern "C" ARM void* func_ov003_02179cfc(char* base, int combatantId, struct Ctx02179cfc* fallback) {
    struct CombatantStruct* combatant = GetCombatantWithFlag0x100(GetBattleStruct(), combatantId);
    if (combatant == NULL) return fallback;

    struct Table9x0217fb68 table = data_ov003_0217fb68;

    int val = GetHalfwordEntryFromField150((struct Field150Holder02052df8*)combatant, table.v[fallback->idx4]);
    if (val == -1) return fallback;

    struct Element020de650* elem = FindElementByKey020dedd0((struct Container020dedd0*)(base + 0x74 + 0x800), val);
    if (elem == NULL) return fallback;

    *(unsigned short*)(base + 0x1000 + 0x48) = val;
    return elem;
}
