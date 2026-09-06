#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

void* GetPointerFromArray0xbd0(unsigned char* obj, unsigned int index);
signed short GetShortFromArray0xc10(unsigned char* obj, unsigned int index);
extern short data_020f29dc[];

// USA: func_020dd300
ARM int CountMatchingRoundedShorts(int mask) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    unsigned char* obj = (unsigned char*)GetPtrField0x2a04(battleStruct);
    signed short* arr = (signed short*)GetPointerFromArray0xbd0(obj + 0x1d4, 0);
    short count = GetShortFromArray0xc10(obj + 0x1d4, 0);
    short result = 0;
    for (short i = 0; i < count; i++) {
        signed short v = arr[i];
        if (v > 0) {
            v -= v % 100;
            for (unsigned char j = 0; j < 12; j++) {
                if (mask & (1 << j)) {
                    if (v == data_020f29dc[j]) {
                        result++;
                        break;
                    }
                }
            }
        }
    }
    return result;
}
