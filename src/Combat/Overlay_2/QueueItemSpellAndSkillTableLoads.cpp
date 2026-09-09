#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern int data_020f2a0c;
extern int data_020f2a18;
extern int strDataPrmSpelltableBin_0216cf21;
extern int strDataPrmSkilltableBin_0216cf39;
extern "C" unsigned int func_0209a804(unsigned int, unsigned int);
extern "C" unsigned int func_0209a338(unsigned int);

// Kicks off the menu's table loads, and is written so it can only run once: bit 0x10 of the word at
// self+0x247c is the "already queued" flag, tested on entry and set on the way out. Three tasks go
// out and their ids are kept at self+0x1ba4, +0x1ba8 and +0x1bac -- itemdt_t_<LG>.nat out of
// data/prm/itemdt_t.gp2, the member and archive names coming from data_020f2a0c and data_020f2a18,
// then data/prm/spelltable.bin and data/prm/skilltable.bin. prm holds ten itemdt_* archives; only
// the _t one is loaded here, and what _t selects is not established.
extern "C" ARM unsigned int QueueItemSpellAndSkillTableLoads(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    int cc = 0;
    unsigned int r4 = 0;
    unsigned int r5 = 0;
    r4 = r0;
    r0 = r4 + 0x2000;
    r0 = *(unsigned int*)((char*)r0 + 0x47c);
    cc = (int)(r0 & 0x10);
    if (cc != 0) { return r0; }
    r0 = (unsigned int)(int)BackgroundLoader::GetInstance();
    r5 = r0;
    ((BackgroundLoader*)(r5))->AddFence();
    r1 = (unsigned int)&data_020f2a18;
    r0 = (unsigned int)&data_020f2a0c;
    r1 = *(unsigned int*)((char*)r1 + 0x0);
    r2 = *(unsigned int*)((char*)r0 + 0x0);
    r0 = r5;
    r3 = 0x0;
    r0 = (unsigned int)((BackgroundLoader*)(r0))->QueueLoadFileInGP2((const char*)(r1), (const char*)(r2), (SafeAllocator*)(r3));
    r1 = r4 + 0x1000;
    *(unsigned int*)((char*)r1 + 0xba4) = (unsigned int)r0;
    r1 = (unsigned int)&strDataPrmSpelltableBin_0216cf21;
    r0 = r5;
    r2 = 0x0;
    r0 = (unsigned int)((BackgroundLoader*)(r0))->QueueLoadFile((const char*)(r1), (SafeAllocator*)(r2));
    r1 = r4 + 0x1000;
    *(unsigned int*)((char*)r1 + 0xba8) = (unsigned int)r0;
    r0 = r5;
    r1 = (unsigned int)&strDataPrmSkilltableBin_0216cf39;
    r2 = 0x0;
    r0 = (unsigned int)((BackgroundLoader*)(r0))->QueueLoadFile((const char*)(r1), (SafeAllocator*)(r2));
    r1 = r4 + 0x1000;
    *(unsigned int*)((char*)r1 + 0xbac) = (unsigned int)r0;
    r0 = r4 + 0x44;
    r0 = r0 + 0x2400;
    r0 = (unsigned int)func_0209a804(r0, r1);
    r0 = r4 + 0x3c;
    r0 = r0 + 0x2400;
    r0 = (unsigned int)func_0209a338(r0);
    r0 = r4 + 0x2000;
    r1 = *(unsigned int*)((char*)r0 + 0x47c);
    r1 = r1 | 0x10;
    *(unsigned int*)((char*)r0 + 0x47c) = (unsigned int)r1;
    return r0;
}
