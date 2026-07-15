#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void* GetFieldPtrAt0x5ca4(void* obj);
void SetField0x3b0Value(struct BattleStruct* battleStruct, int value);

// USA: func_ov001_0215f930
ARM int ClearFieldIfSet_0215f930(void) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    int* p = (int*)GetFieldPtrAt0x5ca4(battleStruct);
    int val = p[1];
    if (val != 0) {
        SetField0x3b0Value(battleStruct, val);
        p[1] = 0;
    }
    return 1;
}
