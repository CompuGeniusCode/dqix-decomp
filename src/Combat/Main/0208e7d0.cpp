#include <globaldefs.h>
#include "Util/Random.h"
#include "Combat/Main/BattleList.h"

struct Obj0208e7d0 {
    char pad0[0xc];
    short* table;
};

extern "C" void* func_0205ec34(void);
int GetField5cb0Value(char* obj);

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_0208e7d0
extern "C" ARM int _Z27GetRandomTableEntry0208e7d0P11Obj0208e7d0(struct Obj0208e7d0* obj) {
    if (obj->table == 0) {
        return 0;
    }
    int count = 8;
    struct BattleStruct* bs = GetBattleStruct();
    func_0205ec34();
    if (GetField5cb0Value((char*)bs) >= 0x13) {
        count = 0x10;
    }
    struct Random* rng = GetBTRandom();
    int idx = NextRandomMax(rng, count);
    return obj->table[idx];
}
