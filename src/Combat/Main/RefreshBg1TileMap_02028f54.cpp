#include <globaldefs.h>
#include "std_library_functions.h"

extern void* data_020fe9a4;
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" void func_020c5b98(int src, int offset, unsigned int size);
int TransferToSubBg0ScreenBase(int arg0, int arg1, unsigned int arg2);

struct GfxModeState02028f54 {
    char pad[0xc];
    int mode;
};
extern struct GfxModeState02028f54 data_020ef74c;

// USA: func_02028f54  (semantic: RefreshBg1TileMap_02028f54)
extern "C" ARM void func_02028f54(void) {
    if (data_020fe9a4 == 0) {
        return;
    }
    if (data_020fe9a4 != 0) {
        memset(data_020fe9a4, 0, 0x6000);
    }
    unsigned short* p = (unsigned short*)data_020fe9a4;
    unsigned short tile = 0;
    int row;
    int col;
    for (row = 0; row < 0x18; row++) {
        for (col = 0; col < 0x20; col++) {
            *p = tile;
            p++;
            tile++;
        }
    }
    int mode = data_020ef74c.mode;
    CleanInvalidateCacheRange(data_020fe9a4, 0x600);
    if (mode == 3) {
        func_020c5b98((int)data_020fe9a4, 0, 0x600);
        return;
    }
    if (mode == 4) {
        TransferToSubBg0ScreenBase((int)data_020fe9a4, 0, 0x600);
        return;
    }
    if (mode == 5) {
        func_020c5b98((int)data_020fe9a4, 0, 0x600);
        return;
    }
    if (mode == 6) {
        TransferToSubBg0ScreenBase((int)data_020fe9a4, 0, 0x600);
        return;
    }
}
