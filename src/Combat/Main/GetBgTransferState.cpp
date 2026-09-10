#include <globaldefs.h>

extern int data_02105254;

// Returns the 0x60-byte block that tracks what has been pushed into background VRAM. func_0203b784
// takes it as its first argument and uses word [screen] as the running destination offset for
// LoadToMainBG0..3CharacterData and LoadToSubBG0..3CharacterData, advancing it by the transfer
// length, with a parallel tile count at +0x20; func_0203b8bc sets the per-layer flags at +0x40 for
// the eight screen and layer pairs. It ends where the main-screen OAM shadow starts at 0x021052b4.
// The split between the character and screen-data halves of the block is only partly worked out.
extern "C" ARM void* GetBgTransferState(void) {
    return &data_02105254;
}
