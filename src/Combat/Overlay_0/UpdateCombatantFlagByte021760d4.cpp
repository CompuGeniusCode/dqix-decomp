#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_ov000_02161318(void*, int);

// USA: func_ov000_021760d4
ARM void UpdateCombatantFlagByte021760d4(void* obj) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    int i;
    for (i = 0; i < 4; i++) {
        void* found = func_ov000_02161318(obj, i);
        if (found != NULL) {
            struct CombatantStruct* c = GetCombatantFromList(battleStruct, i);
            if (c != NULL) {
                void* p = *(void**)((char*)c + 0x138);
                unsigned short val = *(unsigned short*)((char*)p + 0x22);
                int shifted = val << 30;
                *(unsigned char*)((char*)found + 0x2f) = (unsigned char)((unsigned int)shifted >> 30);
            }
        }
    }
}
