#include <globaldefs.h>
#include "std_library_functions.h"
#include "System/Cache.h"

extern "C" void LoadToMainBGStandardPalette(int src, int dstOffset, unsigned int size);
extern "C" void LoadToSubBGStandardPalette(int src, int dstOffset, unsigned int size);
extern "C" void func_02028e90();
extern "C" void func_02028f54();

extern void* data_020fe9a4;
extern unsigned char data_020e7390[0x20];

// USA: func_02028dec
ARM void UploadPendingPalette02028dec(int isSub) {
    unsigned short* reg;
    if (data_020fe9a4 == NULL) {
        return;
    }
    memcpy(data_020fe9a4, data_020e7390, 0x20);
    CleanInvalidateCacheRange(data_020fe9a4, 0x20);
    if (isSub == 0) {
        reg = (unsigned short*)0x400000a;
        *reg = (*reg & 0x43) | 0x4;
        LoadToMainBGStandardPalette((int)data_020fe9a4, 0, 0x20);
    } else {
        reg = (unsigned short*)0x4001008;
        *reg = (*reg & 0x43) | 0x4;
        LoadToSubBGStandardPalette((int)data_020fe9a4, 0, 0x20);
    }
    func_02028e90();
    func_02028f54();
}
