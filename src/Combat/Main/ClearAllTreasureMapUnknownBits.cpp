#include <globaldefs.h>
#include "Grotto/Main/TreasureMapMetadata.h"

int CopyOutBattleRegion0x64f4(void* dst);
int CopyToBattleRegion0x64f4(void* arg);

extern "C" {
    void func_ov017_021cfabc(void);
    void func_ov017_021cf730(int, int);
}

// USA: func_020116c8
ARM void ClearAllTreasureMapUnknownBits(void* obj) {
    unsigned char* p = (unsigned char*)obj;
    p[0x63e4] = 0;
    p[0x63e5] = 0;

    unsigned char localBuf[0xad8];
    CopyOutBattleRegion0x64f4(localBuf);

    for (int i = 0; i < localBuf[0]; i++) {
        ((TreasureMapMetadata*)(localBuf + 2 + i * 0x1c))->ClearInitialByteUnknownBit();
    }

    CopyToBattleRegion0x64f4(localBuf);
    func_ov017_021cfabc();
    func_ov017_021cf730(-1, 0);
}
