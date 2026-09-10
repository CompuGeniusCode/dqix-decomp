#include <globaldefs.h>
#include "std_library_functions.h"

extern unsigned int data_020e7b98[][4];

struct BackgroundLayer {
    char unknown0[0x14];
    void* screenBuffer;
    unsigned int screenSize;
    char unknown1c[3];
    unsigned char layerKind;
};

// Zeroes a background layer's screen (tilemap) buffer, falling back to the buffer the layer
// already owns at +0x14 when none is passed. The size comes from data_020e7b98 indexed by the
// layer's BG type at +0x1f and its screen-size setting at +0x18; the two rows hold
// 0x800/0x1000/0x1000/0x2000 and 0x200/0x800/0x2000/0x8000, the DS text-mode screen sizes and the
// extended-affine ones, whose 16-bit entries double a plain affine map.
// AllocateBackgroundScreenBuffer sizes its allocation the same way.
extern "C" ARM void ClearBackgroundScreenBuffer(BackgroundLayer* layer, void* buffer) {
    if (buffer == NULL) buffer = layer->screenBuffer;
    if (buffer == NULL) return;
    memset(buffer, 0, data_020e7b98[layer->layerKind][layer->screenSize]);
}
