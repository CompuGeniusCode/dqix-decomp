#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" int func_ov017_021d60f4(void*);
struct FieldBlock63d6_115b4;
void SetByteField0x63d6(struct FieldBlock63d6_115b4* obj, unsigned char value);

// USA: func_ov001_021618d0
ARM int SetByteFieldFromBattle_021618d0(void* obj) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    int v = func_ov017_021d60f4(obj);
    SetByteField0x63d6((struct FieldBlock63d6_115b4*)battleStruct, (unsigned char)v);
    return 1;
}
