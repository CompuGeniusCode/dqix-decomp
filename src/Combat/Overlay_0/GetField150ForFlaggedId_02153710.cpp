#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetFieldAt0x150(unsigned char* obj);

// USA: func_ov000_02153710  (semantic: GetField150ForFlaggedId_02153710)
extern "C" ARM int func_ov000_02153710(int unused, int id) {
    int inRange = id >= 0 && id <= 3;
    if (!inRange) return 0;
    struct CombatantStruct* c = GetCombatantWithFlag0x100(GetBattleStruct(), id);
    if (c == 0) return 0;
    return GetFieldAt0x150((unsigned char*)c);
}
