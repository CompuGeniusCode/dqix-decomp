#include <globaldefs.h>

extern "C" void func_020bb740(int* out);
extern "C" void func_020bb92c(int* src);

// Puts the VRAM allocator back to the snapshot held in the object: the 0x28 bytes at obj+0x28 are
// the free-start/free-end pair of each of the five texture-image pools in data_020f1f14, and
// obj+0x60 is the same pair for the texture-palette pool in data_0210cf88. Callers run it the other
// way round from a save/restore -- restore, allocate, then SaveVramAllocatorState to back the cursors up
// again (LoadEv99999ChrPair, func_020dab68) -- so the object carries its own allocator state, swapped in
// for the duration and saved back with the new allocations kept.
extern "C" ARM void RestoreVramAllocatorCursors(char* obj) {
    func_020bb740((int*)(obj + 0x28));
    func_020bb92c((int*)(obj + 0x60));
}
