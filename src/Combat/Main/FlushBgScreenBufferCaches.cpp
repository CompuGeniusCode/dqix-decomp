#include <globaldefs.h>

extern "C" void func_0204b04c(void* bgLayer, int buffer);

struct BackgroundLayer { char unknown0[0x20]; };

struct TextWindowSet {
    char unknown0[0x98];
    BackgroundLayer* bgLayers;
    char unknown9c[0x16];
    unsigned char bgLayerCount;
};

// Cleans the CPU cache over every background screen buffer the object owns: the list of 0x20-byte
// descriptors at +0x98, count at +0xb2. func_0204b04c is the cache half of UploadTilemapToBGScreen
// and sizes the range from data_020e7b98, whose two rows are the DS screen data sizes
// 0x800/0x1000/0x1000/0x2000 for text backgrounds and 0x200/0x800/0x2000/0x8000 for extended
// affine ones. The zero second argument is the buffer override UploadTilemapToBGScreen passes a
// real pointer for, so each layer has its own buffer at +0x14 flushed. The same container keeps its
// 0xe0-byte window elements in a second list at +0x9c, counted at +0xb3.
extern "C" ARM void FlushBgScreenBufferCaches(TextWindowSet* windowSet) {
    unsigned char layer;
    if (windowSet->bgLayers == NULL) return;
    for (layer = 0; layer < windowSet->bgLayerCount; layer++) {
        func_0204b04c(&windowSet->bgLayers[layer], 0);
    }
}
