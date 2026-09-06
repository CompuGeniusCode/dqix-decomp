#include <globaldefs.h>
void* GetPtrField0x2a04(struct BattleStruct*);
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"


// USA: func_02039768
ARM void CopyToBattleField02039768(int unused, void* src) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    memcpy((char*)GetPtrField0x2a04((struct BattleStruct*)(battleStruct)) + 0x2c8d, src, 7);
}
