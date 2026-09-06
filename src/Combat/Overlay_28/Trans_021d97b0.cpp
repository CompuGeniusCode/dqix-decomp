#include <globaldefs.h>

extern int data_ov028_021d9bc4;
extern "C" unsigned int _ZNK6Script9Parameter5ToIntEv();
extern "C" unsigned int _Z31AllocateAndInitEntries_021d9940P24AllocLoopStruct_021d9940P13SafeAllocatorj(unsigned int, unsigned int, unsigned int);

// USA: func_ov028_021d97b0  (semantic: Trans_021d97b0)
extern "C" ARM unsigned int func_ov028_021d97b0(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    r0 = (unsigned int)_ZNK6Script9Parameter5ToIntEv();
    r2 = r0 << 0x10;
    r1 = (unsigned int)&data_ov028_021d9bc4;
    r2 = r2 >> 0x10;
    r0 = *(unsigned int*)((char*)r1 + 0x0);
    r1 = *(unsigned int*)((char*)r1 + 0x4);
    r0 = (unsigned int)_Z31AllocateAndInitEntries_021d9940P24AllocLoopStruct_021d9940P13SafeAllocatorj(r0, r1, r2);
    r0 = 0x1;
    return r0;
}
