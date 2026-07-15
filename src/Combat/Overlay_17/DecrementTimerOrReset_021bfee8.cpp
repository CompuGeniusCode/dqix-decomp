#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void func_ov017_021bff2c(void);
int GetField0x3b4Value(struct BattleStruct* battleStruct);

struct Obj021bfee8 { unsigned char pad[8]; unsigned short field8; };

// USA: func_ov017_021bfee8
ARM int DecrementTimerOrReset_021bfee8(Obj021bfee8* p) {
    unsigned int t = (unsigned int)GetField0x3b4Value(GetBattleStruct());
    if (t < p->field8) {
        p->field8 = (unsigned short)(p->field8 - t);
        return 6;
    }
    p->field8 = 0;
    func_ov017_021bff2c();
    return 8;
}
