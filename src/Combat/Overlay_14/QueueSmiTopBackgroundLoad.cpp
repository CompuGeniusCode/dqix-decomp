#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern int strDataAniBgSmitopPac;

// Asks the background loader for data/ani/bg_smitop.pac once: bit 0x10 of the flag byte at +0x81
// gates it, the counter at +0x7e must still be zero and is bumped straight after, and the handle
// lands at +0x70.
// ov014 is the subjugation-list overlay and its other paths are mon_list.gp2, mons_info2.nat and the
// sml/smi backgrounds, so smi is presumably the monster-info screen -- bg_smiinf.pac and obj_smi.pac
// are its only siblings in data/ani. The abbreviation itself is not established.
extern "C" ARM unsigned int QueueSmiTopBackgroundLoad(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    int cc = 0;
    unsigned int r4 = 0;
    r4 = r0;
    r0 = *(unsigned char*)((char*)r4 + 0x81);
    cc = (int)(r0 & 0x10);
    if (cc == 0) { return r0; }
    r0 = (unsigned int)(int)BackgroundLoader::GetInstance();
    r1 = *(unsigned char*)((char*)r4 + 0x7e);
    cc = (int)(r1) - (int)(0x0);
    if (cc != 0) { return r0; }
    r1 = (unsigned int)&strDataAniBgSmitopPac;
    r2 = 0x0;
    r0 = (unsigned int)((BackgroundLoader*)(r0))->QueueLoadFile((const char*)(r1), (SafeAllocator*)(r2));
    *(unsigned int*)((char*)r4 + 0x70) = (unsigned int)r0;
    r0 = *(unsigned char*)((char*)r4 + 0x7e);
    r0 = r0 + 0x1;
    *(unsigned char*)((char*)r4 + 0x7e) = (unsigned char)r0;
    return r0;
}
