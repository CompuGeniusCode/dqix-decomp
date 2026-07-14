#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "std_library_functions.h"

// USA: func_020ac3c8
ARM int SetBattleFlagBits020ac3c8(unsigned int* dst, short* indices, int count) {
    char* base;
    int i;
    memset(dst, 0, 0x3c);
    base = (char*)GetBattleStruct() + 0x104;
    memcpy(dst, base + 0x7400, 0x3c);
    for (i = 0; i < count; i++) {
        short bit = indices[i];
        if (bit > 0) {
            dst[bit / 32] |= (1 << (bit % 32));
        }
    }
    memcpy(base + 0x7400, dst, 0x3c);
    return 1;
}
