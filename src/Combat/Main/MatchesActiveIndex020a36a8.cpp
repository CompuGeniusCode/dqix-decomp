#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" int func_020100a8(struct BattleStruct*);

struct Combatant020A36A8 {
    char pad[0x2a];
    signed char field2a;
};

// USA: func_020a36a8
ARM int MatchesActiveIndex020a36a8(struct Combatant020A36A8* obj) {
    return obj->field2a == func_020100a8(GetBattleStruct());
}
