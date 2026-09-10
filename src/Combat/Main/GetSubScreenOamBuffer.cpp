#include <globaldefs.h>

extern int data_021056b4;

// Returns the sub screen's OAM shadow buffer. func_0203bdb0 hands this address to LoadToSubOAM with
// a length of 0x400, one whole OAM of 128 entries, and then DMA-fills it with 0xc0 so every sprite
// parks at y=192, off the bottom of the screen. The main screen's buffer is the 0x400 bytes
// immediately before it at 0x021052b4, and func_0203bd88 flushes both together.
extern "C" ARM void* GetSubScreenOamBuffer(void) {
    return &data_021056b4;
}
