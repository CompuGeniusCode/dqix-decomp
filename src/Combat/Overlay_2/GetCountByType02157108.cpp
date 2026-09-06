#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void* GetPtrField0x2a04(struct BattleStruct* battleStruct);

struct S_a0b8c;
int CountNonZeroValues020a0b8c(struct S_a0b8c* p);
int GetFieldAt0x150(unsigned char* obj);
struct Slots02083960;
int CountPositiveSlots02083960(struct Slots02083960* s);

// USA: func_ov002_02157108
ARM int GetCountByType02157108(void* unused, int id) {
    struct BattleStruct* bs = GetBattleStruct();
    int result = 0;
    if (id == 5) {
        void* p = (char*)GetPtrField0x2a04(bs) + 0xe04;
        result = CountNonZeroValues020a0b8c((struct S_a0b8c*)p);
    } else if (id == 4) {
        void* p = GetPtrField0x2a04(bs);
        result = CountNonZeroValues020a0b8c((struct S_a0b8c*)p);
    } else {
        struct CombatantStruct* c = GetCombatantWithFlag0x100(bs, id);
        if (c != NULL) {
            int ptrAsInt = GetFieldAt0x150((unsigned char*)c);
            result = CountPositiveSlots02083960((struct Slots02083960*)ptrAsInt);
        }
    }
    return result;
}
