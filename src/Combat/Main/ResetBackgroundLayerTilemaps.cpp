#include <globaldefs.h>

struct BackgroundLayerHeader;
struct TilemapRecord { unsigned char unknown0[0x10]; };
extern "C" void func_0204a82c(struct BackgroundLayerHeader* layer);
extern "C" void func_0204acb0(struct TilemapRecord* rec);

struct BackgroundLayer {
    unsigned char unknown0[0xc];
    unsigned char unknownc;              // 0xc
    unsigned char unknownd;           // 0xd
    unsigned short fe;             // 0xe
    struct TilemapRecord* tilemaps;    // 0x10
    int screenBuffer;                       // 0x14
    unsigned char unknown18[0x5];      // 0x18..0x1c
    unsigned char tilemapCount;             // 0x1d
};

// Tears a background layer down: drops the screen buffer pointer at +0x14, resets the same
// leading fields ResetBackgroundLayer does, and clears every tilemap record the layer owns --
// the 0x10-byte {width, height, ..., buffer} descriptors func_0204af14 hands out.
// It deliberately leaves the engine/BG assignment at +0x1c and the screen-size fields alone.
// ov020's company-logo setup uses it exactly that way on a stack layer, right after the tilemap
// has been uploaded, so it reads as the teardown half of ResetBackgroundLayer.
// tilemapCount at +0x1d is how many descriptors are in use, the bound func_0204af14 also checks
// against; the capacity AllocateBackgroundLayerTilemaps writes at +0x1e is a separate byte and is
// left alone here. The halfword at +0xe put back to 0xffff is the one PrepareBgBlockForUpload's
// PALT branch reads through the sub-object at +0xc, where 0xffff means clean the whole palette
// buffer rather than named 0x20-byte sub-blocks, while ResetBackgroundLayer reads the same halfword
// as an id; which it is, and what the byte at +0xc holds, are both still not established.
extern "C" ARM void ResetBackgroundLayerTilemaps(struct BackgroundLayer* layer) {
    unsigned char tilemap;
    layer->screenBuffer = 0;
    func_0204a82c((struct BackgroundLayerHeader*)layer);
    layer->unknownc = 0;
    layer->fe = 0xffff;
    if (layer->tilemaps == 0) return;
    tilemap = 0;
    while (tilemap < layer->tilemapCount) {
        func_0204acb0(&layer->tilemaps[tilemap]);
        tilemap++;
    }
}
