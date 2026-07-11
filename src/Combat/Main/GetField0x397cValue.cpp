#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_020100b0
ARM unsigned char GetField0x397cValue(struct BattleStruct* battleStruct) {
    return *(unsigned char*)((char*)battleStruct + 0x397c);
}
