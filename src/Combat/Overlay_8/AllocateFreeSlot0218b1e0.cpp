#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "std_library_functions.h"

struct Bits0218b1e0 { unsigned short low : 14; unsigned short flag : 1; unsigned short hi : 1; };

// USA: func_ov008_0218b1e0
ARM void AllocateFreeSlot0218b1e0(void* obj) {
    struct BattleStruct* bs = GetBattleStruct();
    unsigned char* base = (unsigned char*)bs + 0x1fc + 0x7000;
    unsigned char* p = base + 4;
    for (int i = 0; i < 0x10; p += 0x2c, i++) {
        struct Bits0218b1e0* b = (struct Bits0218b1e0*)(p + 0x12);
        if (!b->flag) {
            memcpy(p, (char*)obj + 0xdf0, 0x2c);
            base[0]++;
            return;
        }
    }
}
