#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern int data_020f2a0c;
extern int data_020f2a18;
extern int data_ov002_0216cf21;
extern int data_ov002_0216cf39;
extern "C" unsigned int _Z19ClearField00209a804Pi(unsigned int, unsigned int);
extern "C" unsigned int _Z26ClearFirstTwoWords0209a338P12Pair0209a338(unsigned int);

// USA: func_ov002_02156bc8  (semantic: Trans_02156bc8)
extern "C" ARM unsigned int func_ov002_02156bc8(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
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
    r1 = (unsigned int)&data_ov002_0216cf21;
    r0 = r5;
    r2 = 0x0;
    r0 = (unsigned int)((BackgroundLoader*)(r0))->QueueLoadFile((const char*)(r1), (SafeAllocator*)(r2));
    r1 = r4 + 0x1000;
    *(unsigned int*)((char*)r1 + 0xba8) = (unsigned int)r0;
    r0 = r5;
    r1 = (unsigned int)&data_ov002_0216cf39;
    r2 = 0x0;
    r0 = (unsigned int)((BackgroundLoader*)(r0))->QueueLoadFile((const char*)(r1), (SafeAllocator*)(r2));
    r1 = r4 + 0x1000;
    *(unsigned int*)((char*)r1 + 0xbac) = (unsigned int)r0;
    r0 = r4 + 0x44;
    r0 = r0 + 0x2400;
    r0 = (unsigned int)_Z19ClearField00209a804Pi(r0, r1);
    r0 = r4 + 0x3c;
    r0 = r0 + 0x2400;
    r0 = (unsigned int)_Z26ClearFirstTwoWords0209a338P12Pair0209a338(r0);
    r0 = r4 + 0x2000;
    r1 = *(unsigned int*)((char*)r0 + 0x47c);
    r1 = r1 | 0x10;
    *(unsigned int*)((char*)r0 + 0x47c) = (unsigned int)r1;
    return r0;
}
