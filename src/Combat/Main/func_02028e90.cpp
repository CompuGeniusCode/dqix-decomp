#include <globaldefs.h>
#include "std_library_functions.h"
#include "System/Cache.h"

void TransferBg1CharData(int arg0, int arg1, unsigned int arg2);
void TransferSubBg0CharData(int arg0, int arg1, unsigned int arg2);

extern void* data_020fe9a4;

struct GfxModeState02028e90 {
    char pad[0xc];
    int mode;
};
extern struct GfxModeState02028e90 data_020ef74c;

// USA: func_02028e90  (semantic: FlushBg1TileMapByMode_02028e90)
extern "C" ARM void func_02028e90(void) {
    if (data_020fe9a4 == 0) {
        return;
    }
    if (data_020fe9a4 != 0) {
        memset(data_020fe9a4, 0, 0x6000);
    }
    int mode = data_020ef74c.mode;
    CleanInvalidateCacheRange(data_020fe9a4, 0x6000);
    if (mode == 3) {
        TransferBg1CharData((int)data_020fe9a4, 0, 0x6000);
        return;
    }
    if (mode == 4) {
        TransferSubBg0CharData((int)data_020fe9a4, 0, 0x6000);
        return;
    }
    if (mode == 5) {
        TransferBg1CharData((int)data_020fe9a4, 0, 0x6000);
        return;
    }
    if (mode == 6) {
        TransferSubBg0CharData((int)data_020fe9a4, 0, 0x6000);
        return;
    }
}
