#include <globaldefs.h>
int GetField0x3acValue(struct BattleStruct*);
#include "Combat/Main/BattleList.h"


struct Combatant020A36A8 {
    char pad[0x2a];
    signed char field2a;
};

// USA: func_020a36a8
ARM int MatchesActiveIndex020a36a8(struct Combatant020A36A8* obj) {
    return obj->field2a == GetField0x3acValue((struct BattleStruct*)(GetBattleStruct()));
}
