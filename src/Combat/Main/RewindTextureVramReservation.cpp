#include <globaldefs.h>
struct TextureVramCursors { unsigned int v[10]; };
struct PaletteVramCursors { unsigned int v[2]; };
struct TextureVramReservation {
    struct TextureVramCursors savedImageCursors;   // 0x00
    struct TextureVramCursors workingImageCursors;   // 0x28
    unsigned int reservedImageBlock;           // 0x50
    unsigned int reservedImageBytes;           // 0x54
    struct PaletteVramCursors savedPaletteCursors;   // 0x58
    struct PaletteVramCursors workingPaletteCursors;   // 0x60
};
// Rewinds this context's texture VRAM cursors to where they stood before its region was reserved,
// which frees everything allocated inside the region. The struct carries two snapshots of the five
// texture image pools from VRAMAllocations.cpp (freeStart_ and freeEnd_ of each, 0x28 bytes) and
// two of the palette allocator pair data_0210cf88; ReserveTextureVramRegion seeds both before
// reserving, RestoreVramAllocatorCursors installs the working copy at +0x28/+0x60 into the live
// allocators and SaveVramAllocatorState captures it back. Zone3D::SwitchZone calls this before
// rebuilding the zone. ReserveTextureVramRegion also leaves +0x50 holding the last texture-image
// block it managed to take and +0x54 the image byte count it really reserved, zeroed when the
// allocation failed, so neither of those is rewound here.
extern "C" ARM void RewindTextureVramReservation(struct TextureVramReservation *reservation) {
    reservation->workingImageCursors = reservation->savedImageCursors;
    reservation->workingPaletteCursors = reservation->savedPaletteCursors;
}
