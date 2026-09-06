#include <globaldefs.h>
#include "Grotto/Main/TreasureMapMetadata.h"
#include "System/Memory.h"

extern "C" int CopyOutBattleRegion0x64f4(void* dst);
extern "C" int CopyToBattleRegion0x64f4(void* arg);

ARM void Test(void* obj) {
    char* base = (char*)obj;
    if (*(unsigned char*)(base + 0x6000 + 0x3e4) == 0) return;

    char buf[0xad8];
    CopyOutBattleRegion0x64f4(buf);
    int i = 0;
    int count = (unsigned char)buf[0];
    while (i < count) {
        TreasureMapMetadata* item = (TreasureMapMetadata*)(buf + 2) + i;
        if (item->GetInitialByteUnknownBit()) {
            VectorizedInvertedMemcpy(base + 0x6450, item, 0x1c);
            CopyToBattleRegion0x64f4(buf);
            break;
        }
        i++;
        count = (unsigned char)buf[0];
    }
}
