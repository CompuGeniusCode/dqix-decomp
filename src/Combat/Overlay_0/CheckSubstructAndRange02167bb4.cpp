#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetSubstructByte0x56(unsigned char* obj);

// USA: func_ov000_02167bb4
ARM int CheckSubstructAndRange02167bb4(unsigned char* obj, int id) {
    struct BattleStruct* battle = GetBattleStruct();
    void* base = *(void**)(obj + 0x29c);
    int key = *(int*)((char*)base + id * 4 + 0x8000 + 0xde0) & 0xff;
    struct CombatantStruct* c = GetCombatantFromList(battle, key);
    int val = c ? (GetSubstructByte0x56((unsigned char*)c) != 0) : 0;
    if (val) return 0;
    if (id < 0 || id >= 8) return 0;
    return 0x7fffffff;
}
