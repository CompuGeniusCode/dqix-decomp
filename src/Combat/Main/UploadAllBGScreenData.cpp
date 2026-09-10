#include <globaldefs.h>

struct BackgroundLayer { unsigned char unknown0[0x20]; };

struct BackgroundManager {
    char unknown0[0x98];
    struct BackgroundLayer* layers;   // 0x98
    char unknown9c[0xb2 - 0x9c];
    unsigned char layerCount;           // 0xb2
};

extern "C" void func_0204b088(struct BackgroundLayer*, int);

// Pushes every 0x20-byte layer record at +0x98, count at +0xb2, through func_0204b088, which uses
// the nibbles of the record's +0x1c to pick one of the eight loaders in data_020f0218 (main and sub
// BG0..BG3 screen data) and hands it the buffer at record+0x14 and a length from data_020e7b98,
// the table of NDS text and extended-affine screen-data sizes. AllocateBackgroundScreenBuffer fills
// that same +0x14 out of the same table, indexed by the size code at +0x18 and the layer kind at
// +0x1f, so one record is one background layer. func_0207fd88 is the same loop over the second
// copy of the pair at +0x2c/+0x38, and the same object owns the 0xe0-byte elements that
// FindTextWindowById searches, behind its own pointer at +0x9c.
extern "C" ARM void UploadAllBGScreenData(struct BackgroundManager* manager) {
    unsigned char layer;
    if (manager->layers == 0) return;
    for (layer = 0; layer < manager->layerCount; layer++) {
        func_0204b088(&manager->layers[layer], 0);
    }
}
