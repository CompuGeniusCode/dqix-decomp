#include <globaldefs.h>

struct BattleStruct;
struct BattleStruct* GetBattleStruct();
unsigned int GetBattleScaleCount(struct BattleStruct* battleStruct);

struct Obj020a620c {
    char pad0[0xa];
    unsigned char index;
};

typedef void (Obj020a620c::*PMF020a620c)();
struct RawTable020a620c { PMF020a620c e[4]; };
extern struct RawTable020a620c data_020e907c;
extern PMF020a620c data_020e6d5c;

// USA: func_020a620c
extern "C" ARM int func_020a620c(Obj020a620c* obj) {
    struct RawTable020a620c table;
    GetBattleScaleCount(GetBattleStruct());
    table = data_020e907c;
    table.e[3] = data_020e6d5c;
    if (table.e[obj->index] == 0) {
        return 0;
    }
    (obj->*table.e[obj->index])();
    return 1;
}
