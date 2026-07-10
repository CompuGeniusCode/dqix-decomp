#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "std_library_functions.h"

extern "C" void func_020120d4(struct BattleStruct*, int);

// USA: func_020a9af8
ARM int LoadBattleRegion0x5cdc(unsigned char* arg) {
    struct BattleStruct* bs = GetBattleStruct();
    func_020120d4(bs, arg[0]);
    memcpy((char*)bs + 0x5cdc, arg + 4, 0x190);
    return 1;
}
