#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "std_library_functions.h"

void SetByte0x5cdaAndClearField0xa(unsigned char*, unsigned char);

// USA: func_020a9af8
ARM int LoadBattleRegion0x5cdc(unsigned char* arg) {
    struct BattleStruct* bs = GetBattleStruct();
    SetByte0x5cdaAndClearField0xa((unsigned char*)bs, arg[0]);
    memcpy((char*)bs + 0x5cdc, arg + 4, 0x190);
    return 1;
}
