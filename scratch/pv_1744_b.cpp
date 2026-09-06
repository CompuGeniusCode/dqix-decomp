#include <globaldefs.h>
#include "Grotto/Main/TreasureMapMetadata.h"
#include "System/Memory.h"

int CopyOutBattleRegion0x64f4(void* dst);
int CopyToBattleRegion0x64f4(void* arg);

// USA: func_02011744
ARM void ScanAndApplyTreasureMapFlag(void* obj) {
    if (!((unsigned char*)obj)[0x63e4]) return;

    unsigned char localBuf[0xad8];
    CopyOutBattleRegion0x64f4(localBuf);

    TreasureMapMetadata* arr = (TreasureMapMetadata*)(localBuf + 2);
    for (int i = 0; i < localBuf[0]; i++) {
        TreasureMapMetadata* entry = (TreasureMapMetadata*)((char*)arr + i * 0x1c);
        if (entry->GetInitialByteUnknownBit()) {
            VectorizedInvertedMemcpy((char*)obj + 0x6450, entry, 0x1c);
            CopyToBattleRegion0x64f4(localBuf);
            return;
        }
    }
}
