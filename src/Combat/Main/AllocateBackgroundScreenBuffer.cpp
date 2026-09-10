#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

extern int data_020e7b98[][4];

struct BackgroundLayer {
    char unknown0[0x14];
    void* screenBuffer;
    unsigned int screenSizeCode;
    unsigned char unknown1c[3];
    unsigned char bgType;
};

// Allocates and zeroes a background layer's screen (tilemap) buffer and stores it at +0x14. The
// size comes from data_020e7b98 indexed by the BG type at +0x1f and the screen size code at +0x18:
// 0x800/0x1000/0x1000/0x2000 for text BGs, 0x200/0x800/0x2000/0x8000 for extended-affine ones,
// each exactly the dimensions in the table at 0x020e7b78 at two bytes per map entry. func_0204b04c
// cache-cleans that same length and func_0204b088 uploads it, so this buffer is what reaches VRAM;
// no symbol names the field. SetTextBgScreenSize writes that pair and always clears +0x1f, and the
// three bytes skipped at +0x1c are the engine/BG nibbles SetBackgroundScroll dispatches on plus the
// tilemap record count ResetBackgroundLayerTilemaps loops over.
extern "C" ARM void AllocateBackgroundScreenBuffer(struct BackgroundLayer* layer, SafeAllocator* alloc) {
    unsigned int size;
    void* buffer;
    if (alloc == NULL) return;
    size = data_020e7b98[layer->bgType][layer->screenSizeCode];
    buffer = alloc->Allocate(size);
    layer->screenBuffer = buffer;
    memset(buffer, 0, size);
}
