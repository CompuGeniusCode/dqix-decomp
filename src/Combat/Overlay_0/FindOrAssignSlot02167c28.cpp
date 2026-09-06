#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" int _ZNK8Object3D9GetRadiusEv(unsigned char* obj);
int CheckSubstructAndRange02167bb4(unsigned char* obj, int id);

// USA: func_ov000_02167c28
ARM int FindOrAssignSlot02167c28(unsigned char* obj, int id) {
    struct BattleStruct* battle = GetBattleStruct();
    struct CombatantStruct* combatant = GetCombatantFromList(battle, id);
    if (!combatant) return -1;

    for (int i = 0; i < 8; i++) {
        int* p = (int*)((char*)*(void**)(obj + 0x29c) + 0x8000 + 0xde0);
        int val = p[i] & 0xff;
        if (val == id) {
            p[i] = -1;
            break;
        }
    }

    int threshold = _ZNK8Object3D9GetRadiusEv((unsigned char*)combatant);
    for (int j = 0; j < 8; j++) {
        if (CheckSubstructAndRange02167bb4(obj, j) < threshold) continue;
        *(int*)((char*)*(void**)(obj + 0x29c) + j * 4 + 0x8000 + 0xde0) = id;
        return j;
    }
    return -1;
}
