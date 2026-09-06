#include <globaldefs.h>

extern "C" void _Z28LockStagedTextureVRAMCopyingv();
extern "C" void MapVRAMBanksToTextureImage(int handle);
extern "C" void MapVRAMBanksToTexturePalette(int value);
extern "C" void MapVRAMBanksToMainBG(int v);
extern "C" void MapVRAMBanksToMainObj(int mode);
ARM void ConfigurePairMode020bb48c(unsigned int mode, int installHandlers);
extern "C" void MapVRAMBanksToSubBG(int);
extern "C" void MapVRAMBanksToSubObj(int value);
extern "C" void _Z26UpdateVRAMStagingVRAMBanksv(void);
extern "C" void _Z30UnlockStagedTextureVRAMCopyingv(void);

struct Obj02097b34 {
    unsigned int field0;
    int field4;
    int field8;
    int fieldc;
    int field10;
    int field14;
    char pad18[0x1e - 0x18];
    unsigned char field1e;
};

// USA: func_02097b34
extern "C" ARM void func_02097b34(struct Obj02097b34* obj) {
    _Z28LockStagedTextureVRAMCopyingv();
    if (obj->field1e & 1) {
        unsigned int mask;
        unsigned short count;

        MapVRAMBanksToTextureImage(obj->field0);
        MapVRAMBanksToTexturePalette(obj->field4);
        MapVRAMBanksToMainBG(obj->field8);
        MapVRAMBanksToMainObj(obj->fieldc);

        mask = obj->field0;
        count = 0;
        while (mask != 0) {
            count = count + 1;
            mask &= mask - 1;
        }
        ConfigurePairMode020bb48c(count, 1);
    }
    if (obj->field1e & 2) {
        MapVRAMBanksToSubBG(obj->field10);
        MapVRAMBanksToSubObj(obj->field14);
    }
    _Z26UpdateVRAMStagingVRAMBanksv();
    _Z30UnlockStagedTextureVRAMCopyingv();
}
