#include <globaldefs.h>

extern "C" void func_0203aa80(void* obj, int arg2);

// Frees whatever LoadSeGroupAndSelectSeqArc loaded, by rewinding the sound heap to the level saved at +0xc0. The
// heap is the holder at +0x0; func_020bdac0 is the save side and func_020bdb0c
// the restore side -- it walks the holder's children from the mark up, runs each one's callback at
// +0xc, unlinks it, then drops the allocator back to the mark. Nothing is unloaded selectively, and
// the selected sequence archive at +0xc4 is left alone, so a caller that reloads a group without
// re-selecting keeps playing from the old archive number. 0x0205eb80 is a byte-identical copy.
extern "C" ARM void FreeSeGroup(void* obj) {
    func_0203aa80(obj, *(int*)((char*)obj + 0xc0));
}
