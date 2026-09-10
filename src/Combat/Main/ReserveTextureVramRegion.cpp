#include <globaldefs.h>

extern "C" void func_020bb700(int* out);
extern "C" void func_020bb910(int* cursorsOut);
extern "C" int func_020bb588(unsigned int size, int paired, int defaultOffset);
extern "C" int func_020bb7cc(unsigned int size, int eightByteAlign, int unknown);

struct TextureImageCursors { unsigned int v[10]; };
struct TexturePaletteCursors { int v[2]; };
struct TextureVramReservation {
    TextureImageCursors rewindImageCursors;
    TextureImageCursors imageCursors;
    int lastImageBlock;
    int imageBytesReserved;
    TexturePaletteCursors rewindPaletteCursors;
    TexturePaletteCursors paletteCursors;
    int paletteBlock;
    int paletteBytesReserved;
};

// Reserves a scene's texture VRAM and snapshots the cursors first, so RewindTextureVramReservation
// can hand the region back by copying it over the working one. Images go to func_020bb588, which
// carves the five pools in the table at 0x020f1f00 and refuses 0x7fff0 or more, the DS texture-image
// ceiling; the request is split into 0x20000 steps, one VRAM slot, and only the last block's pointer
// is kept. Palettes go to func_020bb7cc on the pair at data_0210cf88. A size is zeroed when its
// allocation failed, so +0x54 and +0x6c say what was reserved, not what was asked. The two
// allocators are MaybeAllocateTextureImageVRAM and MaybeAllocateTexturePaletteVRAM of
// src/Graphics/VRAMAllocations.cpp, whose remaining arguments this always passes as 0, and the
// copies at +0x28 and +0x60 are the working set RestoreVramAllocatorCursors installs and
// SaveVramAllocatorState writes back.
extern "C" ARM void ReserveTextureVramRegion(void* pReservation, int imageBytes, int paletteBytes) {
    struct TextureVramReservation* reservation = (struct TextureVramReservation*)pReservation;
    func_020bb700((int*)&reservation->rewindImageCursors);
    reservation->imageCursors = reservation->rewindImageCursors;
    func_020bb910(reservation->rewindPaletteCursors.v);
    int remaining = imageBytes;
    reservation->paletteCursors = reservation->rewindPaletteCursors;
    reservation->lastImageBlock = 0;

    while (remaining > 0) {
        if (remaining > 0x20000) {
            reservation->lastImageBlock = func_020bb588(0x20000, 0, 0);
            remaining -= 0x20000;
        } else {
            reservation->lastImageBlock = func_020bb588(remaining, 0, 0);
            remaining = 0;
        }
    }
    if (imageBytes != 0 && reservation->lastImageBlock == 0) imageBytes = 0;

    reservation->paletteBlock = 0;
    if (paletteBytes != 0) {
        reservation->paletteBlock = func_020bb7cc(paletteBytes, 0, 0);
    }
    if (paletteBytes != 0 && reservation->paletteBlock == 0) paletteBytes = 0;

    reservation->imageBytesReserved = imageBytes;
    reservation->paletteBytesReserved = paletteBytes;
}
