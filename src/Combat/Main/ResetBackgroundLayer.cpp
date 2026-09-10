#include <globaldefs.h>

struct BackgroundLayer;
extern "C" ARM void func_0204a82c(struct BackgroundLayer*);

struct BackgroundLayer {
    char unknown0[0xc];
    unsigned char unknownc;
    unsigned char unknownd;
    unsigned short paletteChunkMask;
    int tilemapRecords;
    int screenBuffer;
    int screenSizeCode;
    unsigned char engine : 4;
    unsigned char bgIndex : 4;
    unsigned char tilemapRecordCount;
    unsigned char unknown1e;
    unsigned char bgType;
};

// Clears a background-layer descriptor: the CHAR chunk header fields func_0204a8f4 copies in, the
// three words at +0x10..+0x18 and the engine/BG nibbles at +0x1c, and sets the palette chunk mask
// at +0xe to 0xffff rather than to zero. Only the descriptor is touched; no hardware register is
// written. The nibbles are what make this a per-engine, per-BG layer - UploadBgResourceByTag
// dispatches them through three parallel tables, one each for CHAR, PALT and SCRN, and
// func_02020cb8 sets them to (1,1) before calling SetBackgroundScroll. The three words are the ones
// the rest of the family works on: ResetBackgroundLayerTilemaps clears the 0x10-byte tilemap
// records at +0x10 and counts them with the byte at +0x1d, and AllocateBackgroundScreenBuffer
// allocates the screen buffer at +0x14 for the length data_020e7b98[+0x1f][+0x18] gives. The mask
// at +0xe is the halfword func_0204abcc reads as +0x2 of the sub-object at +0xc: 0xffff hands the
// whole payload to the loader in one call, otherwise one call per 0x20-byte chunk the low eight
// bits select. The caller then puts 0x6000 in +0x0 and 0xfffe in +0xe.
extern "C" ARM void ResetBackgroundLayer(struct BackgroundLayer* layer) {
    func_0204a82c((struct BackgroundLayer*)layer);
    layer->unknownc = 0;
    layer->paletteChunkMask = 0xffff;
    layer->tilemapRecords = 0;
    layer->screenBuffer = 0;
    layer->screenSizeCode = 0;
    layer->engine = 0;
    layer->bgIndex = 0;
    layer->tilemapRecordCount = 0;
    layer->unknown1e = 0;
    layer->bgType = 0;
}
