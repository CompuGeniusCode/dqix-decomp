#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);
struct IntField0x68_020377bc;
int GetIntAt0x68(struct IntField0x68_020377bc* obj);
int GetIntAt0x64(unsigned char* obj);

// USA: func_ov000_021635e4
extern "C" ARM short func_ov000_021635e4(int id, int mode) {
    struct BattleStruct* bs = GetBattleStruct();
    if (bs == 0) {
        return 0x10a;
    }
    struct CombatantStruct* c = GetCombatantUnchecked(bs, id);
    if (c == 0) {
        return 0x10a;
    }
    int result = 0x1000;
    int b = GetIntAt0x68((struct IntField0x68_020377bc*)c);
    int a = GetIntAt0x64((unsigned char*)c);
    switch (mode) {
        case 0:
            if (b > a) {
                b = a;
            }
            result = b;
            break;
        case 1:
            if (b < a) {
                b = a;
            }
            result = b;
            break;
        case 2:
            result = (b + a) >> 1;
            break;
        case 3:
            result = a;
            break;
        case 4:
            result = b;
            break;
    }
    return (short)result;
}
