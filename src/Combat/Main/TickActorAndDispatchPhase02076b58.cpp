#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct Obj02076b58;
typedef void (Obj02076b58::*PMF02076b58)();

struct Obj02076b58 {
    char pad0[0x130];
    int field130;
    char pad1[0x18];
    int field14c;
    int field150;
    int field154;
};

extern PMF02076b58 data_020e892c[];

extern "C" void func_020332ac(void* obj);
extern "C" void func_020790ac(void* obj);
int GetField0x3b4Value(struct BattleStruct* battleStruct);

// USA: func_02076b58
ARM void TickActorAndDispatchPhase02076b58(Obj02076b58* obj) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    func_020332ac(obj);
    obj->field14c += GetField0x3b4Value(battleStruct);
    if (obj->field130 != 0) {
        obj->field154 += GetField0x3b4Value(battleStruct);
    }
    obj->field150 += 1;
    func_020790ac(obj);
    (obj->*data_020e892c[obj->field130])();
}
