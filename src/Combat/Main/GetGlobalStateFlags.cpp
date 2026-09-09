#include <globaldefs.h>

extern int data_02114e04;

// Returns the game's one global bit-flag word, a lone bss u32 that __sinit_020e66a0 does nothing but
// zero. Most call sites hand it straight to the flag-word helpers at 0x02046708, 0x020466e4 and
// 0x020466f4; the rest stash the pointer or use the accessors at 0x0204671c, 0x02046724 and
// 0x02046730. Callers sit in main plus fourteen overlays, so this is engine plumbing rather than
// anything one subsystem owns. Only one bit is pinned down: 0x02000000 means the top 0x8000 bytes of
// fileStagingBuffer are spoken for, and ExtractFileFromGP2 subtracts that much before reading.
extern "C" ARM void* GetGlobalStateFlags(void) {
    return (void*)&data_02114e04;
}
