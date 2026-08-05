#include <globaldefs.h>

extern "C" unsigned int _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(unsigned int, unsigned int);
extern "C" unsigned int _Z26InitAllocatorArray02186e74P17Container02186e74P13SafeAllocator(unsigned int, unsigned int);
extern "C" unsigned int _Z29GetField110ArrayValue021574d4Pvi(unsigned int, unsigned int);
extern "C" unsigned int _Z30SetPendingFlagAndSync_0215a878Pc(unsigned int, unsigned int, unsigned int);
extern "C" unsigned int _Z37ResetAllocatorsAndClearFields0215b428Ph(unsigned int, unsigned int, unsigned int);
extern "C" unsigned int _ZN13SafeAllocator5ResetEv(unsigned int);
extern "C" unsigned int func_ov013_02186eec(unsigned int, unsigned int);

// USA: func_ov002_021682c0  (semantic: Trans_021682c0)
extern "C" ARM unsigned int func_ov002_021682c0(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    r4 = r0;
    r1 = r4 + 0x2000;
    r2 = *(unsigned int*)((char*)r1 + 0x47c);
    r2 = r2 & ~0x4;
    *(unsigned int*)((char*)r1 + 0x47c) = (unsigned int)r2;
    r0 = (unsigned int)_Z30SetPendingFlagAndSync_0215a878Pc(r0, r1, r2);
    r0 = r4 + 0x2c8;
    r0 = r0 + 0xc00;
    r1 = 0x1;
    r0 = (unsigned int)_Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(r0, r1);
    r1 = r4 + 0x2000;
    r2 = 0x0;
    *(unsigned char*)((char*)r1 + 0x454) = (unsigned char)r2;
    r0 = r4;
    *(unsigned char*)((char*)r1 + 0x455) = (unsigned char)r2;
    r0 = (unsigned int)_Z37ResetAllocatorsAndClearFields0215b428Ph(r0, r1, r2);
    r0 = r4 + 0x850;
    r0 = (unsigned int)_ZN13SafeAllocator5ResetEv(r0);
    r0 = r4 + 0x104;
    r0 = r0 + 0x1c00;
    r1 = 0x1;
    r0 = (unsigned int)func_ov013_02186eec(r0, r1);
    r0 = r4 + 0x104;
    r0 = r0 + 0x1c00;
    r1 = r4 + 0x850;
    r0 = (unsigned int)_Z26InitAllocatorArray02186e74P17Container02186e74P13SafeAllocator(r0, r1);
    r0 = r4 + 0x1c00;
    r1 = *(short*)((char*)r0 + 0x8);
    r0 = r4;
    r0 = (unsigned int)_Z29GetField110ArrayValue021574d4Pvi(r0, r1);
    r1 = r4 + 0x1000;
    *(unsigned char*)((char*)r1 + 0xd6b) = (unsigned char)r0;
    r0 = *(unsigned int*)((char*)r1 + 0xbc0);
    r0 = r0 + 0x1;
    *(unsigned int*)((char*)r1 + 0xbc0) = (unsigned int)r0;
    return r0;
}
