#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void* GetPtrField0x2a04(struct BattleStruct* battleStruct);
struct KeyMap020a0b3c;
signed char LookupValueByKey020a0b3c(struct KeyMap020a0b3c* map, int key);

extern "C" int func_ov017_021d60f4(void*);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_0209d9c4
ARM int SetCombatFlagFromKeyLookup(void* p) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    void* result = GetPtrField0x2a04(battleStruct);
    int raw = func_ov017_021d60f4(p);
    struct KeyMap020a0b3c* map = (struct KeyMap020a0b3c*)((char*)result + 0x204 + 0xc00);
    signed char val = LookupValueByKey020a0b3c(map, (short)raw);
    func_ov017_021d6134((char*)p + 0x8, val);
    return 1;
}
