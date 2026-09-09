#include <globaldefs.h>

extern "C" void func_020bb700(int* out);
extern "C" void func_020bb910(int* dst);

// Captures the current VRAM allocation cursors into the context: the five texture-image pools of
// data_020f1f14, freeStart/freeEnd each, as ten words at +0x28, and the texture-palette window
// data_0210cf88 as two words at +0x60. Those are the globals MaybeAllocateTextureImageVRAM and
// MaybeAllocateTexturePaletteVRAM carve out of. RestoreVramAllocatorCursors is the other half, writing a saved set
// back over the globals -- a caller installs its own cursors, loads, then saves the new watermarks
// back here, which is exactly what ov015's func_0218df0c does around a model load.
extern "C" ARM void SaveVramAllocatorState(char* obj) {
    func_020bb700((int*)(obj + 0x28));
    func_020bb910((int*)(obj + 0x60));
}
