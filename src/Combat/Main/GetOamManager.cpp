#include <globaldefs.h>

extern int data_02105ab4;

// Returns the OAM manager singleton. data_02105ab4 is referenced by nothing but this getter and
// its static constructor, which runs 0x0203c73c -> 0x0203bd24: that stores the sub-screen OAM
// shadow buffer (data_021056b4, the buffer GetSubScreenOamBuffer returns) at +0x10 and sets the
// bytes at +0xc and +0xd. Those two bytes are the per-engine dirty flags 0x0203bdb0 tests before
// LoadToMainOAM and LoadToSubOAM upload the two 0x400-byte shadow buffers, and 0x0203be58 is the
// setter callers use to raise them by engine index.
// Callers declare the function as taking an argument; the ROM function takes none and ignores it.
extern "C" ARM void* GetOamManager(void) {
    return &data_02105ab4;
}
