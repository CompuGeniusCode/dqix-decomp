#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_ov000_02161318(void* obj, int index);
struct CombatantStruct* GetCombatantWithFlag0x100(struct BattleStruct* battleStruct, int combatantId);
int GetFieldAt0x150(unsigned char* obj);

// USA: func_ov000_02175fc8  (semantic: ApplyStatusToSlots_02175fc8)
extern "C" ARM void func_ov000_02175fc8(void* obj) {
    char* e;
    int i;
    for (i = 0; i < 4; i++) {
        e = (char*)func_ov000_02161318(obj, i);
        if (e == NULL) continue;
        struct BattleStruct* bs = GetBattleStruct();
        struct CombatantStruct* c = GetCombatantWithFlag0x100(bs, *(int*)(e + 0x4c));
        if (c == NULL) continue;
        int* p = *(int**)((char*)c + 0x130);
        if (*p & 4) {
            *(int*)(e + 0x28) |= 4;
        }
        int val150 = GetFieldAt0x150((unsigned char*)c);
        if (val150 != 0) {
            *(unsigned char*)(e + 0x443) = (unsigned char)*(int*)(val150 + 0x94c);
        }
    }
}
