#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" int func_ov017_021d60f4(void*);
void SelectTableValueAndDispatch(char* obj, int index);

// USA: func_ov001_02162148  (semantic: DispatchTableEntry_02162148)
extern "C" ARM int func_ov001_02162148(void* obj) {
    struct BattleStruct* bs = GetBattleStruct();
    int idx = func_ov017_021d60f4(obj);
    SelectTableValueAndDispatch((char*)bs, idx);
    return 1;
}
