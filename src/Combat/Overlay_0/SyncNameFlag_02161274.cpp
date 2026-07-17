#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void BuildName020488ec(char* obj);
struct CombatantStruct* GetCombatantWithFlag0x400(struct BattleStruct* battleStruct, int combatantId);

// USA: func_ov000_02161274
ARM void SyncNameFlag_02161274(struct CombatantStruct* self) {
    if (self == NULL) {
        return;
    }
    void* inner = *(void**)((char*)self + 0x144);
    if (inner == NULL) {
        return;
    }
    short val = *(short*)((char*)inner + 8);
    struct BattleStruct* bs = GetBattleStruct();
    int i = 0;
    while (i < 8) {
        struct CombatantStruct* c = GetCombatantWithFlag0x400(bs, i + 0xc0);
        if (c != NULL && c != self) {
            void* cInner = *(void**)((char*)c + 0x144);
            if (cInner != NULL) {
                short cVal = *(short*)((char*)cInner + 8);
                if (cVal == val) {
                    unsigned char* base138 = *(unsigned char**)((char*)c + 0x138);
                    if (base138[0x25] == 0 && *((unsigned char*)c + 0x18d) == 0) {
                        base138[0x25] = 1;
                        *((unsigned char*)c + 0x18d) = 1;
                        BuildName020488ec((char*)c);
                        return;
                    }
                }
            }
        }
        i++;
    }
}
