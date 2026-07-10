#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "std_library_functions.h"

struct Region02027ad8 {
    char pad[0x3cc];
    unsigned char slots[0x40][0x200];
};

// USA: func_02027ad8
ARM void ClearOrFillBattleRegion02027ad8(int unused, int flag) {
    struct Region02027ad8* r = (struct Region02027ad8*)GetBattleStruct();
    if (flag != 0) {
        memset(r->slots[54], 0xff, sizeof(r->slots[54]));
    } else {
        memset(r->slots[54], 0, sizeof(r->slots[54]));
    }
}
