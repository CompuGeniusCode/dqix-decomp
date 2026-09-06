#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* _Z30FindRecordByShortField020108f0Pvi(void* obj, int value);
extern "C" void* _Z28FindSlotWithNegShort02010954Pc(char* base);
extern "C" void _Z24SetPointerFields02053c4cPcS_(char* obj, char* p);
extern "C" void func_020c9be0(void);

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_02053c74
ARM void RegisterOrAllocateCombatant02053c74(char* obj, int idx) {
    struct BattleStruct* bs = GetBattleStruct();
    char* rec = (char*)_Z30FindRecordByShortField020108f0Pvi(bs, idx);
    if (!rec) {
        rec = (char*)_Z28FindSlotWithNegShort02010954Pc((char*)bs);
        if (rec) {
            *(short*)(rec + 0x568) = idx;
        } else {
            func_020c9be0();
        }
    }
    _Z24SetPointerFields02053c4cPcS_(obj, rec);
}
