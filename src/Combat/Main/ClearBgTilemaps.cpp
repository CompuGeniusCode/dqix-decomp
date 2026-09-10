#include <globaldefs.h>

struct BackgroundLayer { char unknown0[0x20]; };
extern "C" void ClearBackgroundScreenBuffer(BackgroundLayer*, void*);

struct TextWindowManager {
    char unknown0[0x98];
    BackgroundLayer* bgLayers;
    char unknown9c[0x16];
    unsigned char bgLayerCount;
};

// Blanks the tilemap of every background layer this object owns. ClearBackgroundScreenBuffer memsets an
// entry's buffer using data_020e7b98[kind][size], and the two rows of that table are
// 0x800/0x1000/0x1000/0x2000 and 0x200/0x800/0x2000/0x8000 -- the DS text and extended affine
// map sizes for the four BGxCNT screen-size codes -- so +0x1f is the layer kind and +0x18 its
// screen size. The layer count is the byte at +0xb2, the same one UploadAllBGScreenData iterates.
// The same object carries the 0xe0-byte text windows at +0x9c with their live count at +0xb4 and
// the active window id at +0xb0, and FindCurrentTextWindow null-checks this very bgLayers pointer
// before looking one up, which is what ties the two halves together.
extern "C" ARM void ClearBgTilemaps(TextWindowManager* manager) {
    unsigned char layer;
    if (manager->bgLayers == NULL) return;
    for (layer = 0; layer < manager->bgLayerCount; layer++) {
        ClearBackgroundScreenBuffer(&manager->bgLayers[layer], NULL);
    }
}
