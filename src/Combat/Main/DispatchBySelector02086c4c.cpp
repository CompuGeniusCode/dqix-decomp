#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

int GetFieldAt0x150(unsigned char* obj);
struct Slots02083994;
int CountMatchingUntilNegative02083994(struct Slots02083994* s, int value);
struct KeyMap020a0b3c;
signed char LookupValueByKey020a0b3c(struct KeyMap020a0b3c* map, int key);
extern "C" short func_0207c7a0(void* map, int key, int amount);

// USA: func_02086c4c
ARM short DispatchBySelector02086c4c(unsigned char* self, int selector, int key) {
    struct BattleStruct* bs = GetBattleStruct();
    short result = 0;
    int take;
    if (selector < 0) {
        goto zero;
    }
    if (selector <= 3) {
        take = 1;
        goto after;
    }
zero:
    take = 0;
after:
    if (take) {
        struct CombatantStruct* c = GetCombatantWithFlag0x100(bs, selector);
        if (c == NULL) {
            return 0;
        }
        void* x = (void*)GetFieldAt0x150((unsigned char*)c);
        if (x == NULL) {
            return 0;
        }
        result += CountMatchingUntilNegative02083994((struct Slots02083994*)x, key);
    } else if (selector == 4) {
        result = LookupValueByKey020a0b3c((struct KeyMap020a0b3c*)self, key);
    } else if (selector == 5) {
        result = func_0207c7a0(self + 0x1d4, key, 9);
    } else if (selector == 6) {
        result = LookupValueByKey020a0b3c((struct KeyMap020a0b3c*)(self + 0xe04), key);
    }
    return result;
}
