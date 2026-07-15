#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct BattleStruct* GetBattleStruct();
int GetField0x3b0Value(struct BattleStruct* battleStruct);
extern "C" int func_ov017_021d60f4(void* obj);

// USA: func_ov001_02163248
ARM int SetByteField265FromCond_02163248(void* obj) {
    struct BattleStruct* battleStruct = (struct BattleStruct*)GetField0x3b0Value(GetBattleStruct());
    if (battleStruct == NULL) return 1;
    *(unsigned char*)((char*)battleStruct + 0x265) = (func_ov017_021d60f4(obj) == 0);
    return 1;
}
