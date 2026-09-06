#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void func_ov011_021848a0(void* obj, int val);

// USA: func_ov004_02165868  (semantic: SetOv011FieldAndClearBattleFlag_02165868)
extern "C" ARM int func_ov004_02165868(void* obj) {
    func_ov011_021848a0(obj, 0x6c);
    struct BattleStruct* battle = GetBattleStruct();
    *((unsigned char*)battle + 0x6000 + 0x46e) = 0;
    return 0;
}
