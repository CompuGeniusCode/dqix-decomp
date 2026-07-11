#include <globaldefs.h>
int GetBattleTimerDelta(struct BattleStruct*);
#include "Combat/Main/BattleList.h"


struct BattleTimer0202441c {
    char pad[0x9bc];
    unsigned int accum;
    unsigned char state;
};

// USA: func_0202441c
ARM void AccumulateBattleTimer0202441c(struct BattleTimer0202441c* p) {
    p->accum += GetBattleTimerDelta((struct BattleStruct*)(GetBattleStruct()));
    if (p->accum >= 0x4b0) {
        p->state = 0;
        p->accum = 0;
        return;
    }
    if (p->accum >= 0x1f4) {
        p->state = 1;
    }
}
