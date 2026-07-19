#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void* GetPtrField0x2a04(struct BattleStruct* battleStruct);
struct CombatantStruct* GetCombatantWithFlag0x100(struct BattleStruct* battleStruct, int combatantId);
int GetFieldAt0x150(unsigned char* obj);
struct KeyMap020a095c;
int AddKeyValueClamped020a095c(struct KeyMap020a095c* map, int key, int amount);

// USA: func_ov017_021b6bb8
ARM void AddPositiveField150EntriesToMap_021b6bb8(int combatantId) {
    struct BattleStruct* bs = GetBattleStruct();
    void* keymap = GetPtrField0x2a04(bs);
    struct CombatantStruct* c = GetCombatantWithFlag0x100(bs, combatantId);
    if (c == NULL) {
        return;
    }

    char* base = (char*)GetFieldAt0x150((unsigned char*)c);
    unsigned char i = 0;
    while (i < 8) {
        char* p = base + i * 2 + 0x400;
        short v = *(short*)(p + 0x54);
        if (v > 0) {
            AddKeyValueClamped020a095c((struct KeyMap020a095c*)keymap, v, 1);
        }
        i = (i + 1) & 0xff;
    }
}
